#include<lpc21xx.h>
#include<string.h>
#include<stdio.h>
#include "lcd.h"
#include "i2c_eeprom.h"
#include "R305.h"
#include "type.h"
#include "edit.h"
#include "delay.h"
#include "kpm.h"
#include "l293d.h"
#include "display.h"
#include "type.h"

extern unsigned int flag1;
extern unsigned int pass;
extern unsigned int id;
extern unsigned int idcount;
u8 buf2[5];
u8 buf3[5];

void set_id()
{
	u32 x = 0;
	u8 ch = 0;
	INPUT:
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("ENTER ID : ");
	/*id = ReadNUM();
	CmdLCD(0xc0);
	u32LCD(id);
	delay_ms(1000);*/
	id = ReadNUMWithDisp(&x);
	if(x == 1)
	{
		display_empty();
		goto INPUT;
	}
	else if(x == 2)
	{
		display_input_format();
		goto INPUT;
	}
	else if(x == 3)
	{
		display_pass_len();
		goto INPUT;
	} 
	ch=id+48;
	i2c_eeprom_write(0x50,0x0000,ch);
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD(" --ID SAVED-- ");
	delay_ms(1000);
}
void set_pass(u32 k)
{
	u32 x = 5;		//  X = 5 TO HIDE PASS 
	INPUT:
	memset(buf2,'\0',5);
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("ENTER PASSWORD");
	pass = ReadNUMWithDisp(&x);
	if(x == 1)
	{
		display_empty();
		x=5;
		goto INPUT;
	}
	else if(x == 2)
	{
		display_input_format();
		x=5;
		goto INPUT;
	}
	else if(x == 3)
	{
		display_pass_len();
		x=5;
		goto INPUT;
	}
	sprintf((char *)buf2,"%d",pass);
	i2c_eeprom_page_write(0x50,0x0001,buf2,5);			
}
int confirm_pass(u32 k)
{
	u32 x = 5,tp=0;
	INPUT:
	memset(buf3,'\0',5);
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("CONFIRM PASSWORD");
	tp = ReadNUMWithDisp(&x);
	if(x == 1)
	{
		display_empty();
		x=5;
		goto INPUT;
	}
	else if(x == 2)
	{
		display_input_format();
		x=5;
		goto INPUT;
	}
	else if(x == 3)
	{
		display_pass_len();
		x=5;
		goto INPUT;
	}
	i2c_eeprom_page_read(0x50,0x0001,buf3,5);			
	sscanf((char *)buf3,"%d",&pass);
	if(tp == pass)
	{
		i2c_eeprom_page_write(0x50,0x0001,buf2,5);			
		display_pass_saved();
		return 1;
	}
	else																																		 
	{
		display_invalid_pass();
		x=5;
		goto INPUT;
	}
}
int verify_id()
{
	u32 tid =0,x=0;
	INPUT:
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("ENTER ID : ");
	tid = ReadNUMWithDisp(&x);
	/*tid = ReadNUM();
	CmdLCD(0xc0);
	u32LCD(tid);
	delay_ms(1000);*/
	if(x == 1)
	{
		display_empty();
		goto INPUT;
	}
	else if(x == 2)
	{
		display_input_format();
		goto INPUT;
	}
	x = i2c_eeprom_read(0x50,0x0000);			
	x-=48;
	id = x;
	if(tid == id)
		return 1;
	else
	{
		display_invalid_id();
		return 0;
	}
}
int verify_pass()
{
	u32 x = 5,tp =0;
	INPUT:
	memset(buf3,'\0',5);
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("ENTER PASSWORD");
	tp = ReadNUMWithDisp(&x);
	if(x == 1)
	{
		display_empty();
		x = 5;
		goto INPUT;
	}
	else if(x == 2)
	{
		display_input_format();
		x=5;
		goto INPUT;
	}
	else if(x == 3)
	{
		display_pass_len();
		x=5;
		goto INPUT;
	}
	i2c_eeprom_page_read(0x50,0x0001,buf3,5);			
	sscanf((char *)buf3,"%d",&pass);
	if(tp == pass)
		return 1;
	else
	{
		CmdLCD(0x01);
		CmdLCD(0x80);
		StrLCD("INVALID PASSWORD");
		delay_ms(1000);
		return 0;
	}

}
int verify_finger(u32 k)
{
	u32 x = 0;
	x = search_fp()-1;
	/*CmdLCD(0x01);
	CmdLCD(0x80);
	u32LCD(x);
	CharLCD(32);
	u32LCD(id);
	delay_ms(1000);*/
		
	if(x == id)
		return 1;
	else
		return 0;
}
void edit_all()
{
	int x =0 ;
	if(flag1 == 1)
	{
		flag1 = 0;
		while(1)
		{
			CmdLCD(0x01);
			CmdLCD(0x80);
			StrLCD("1.EDIT PASS 3.EX");
			CmdLCD(0xC0);
			StrLCD("2.EDIT FINGER ");
			x = ReadNUM();
			if(x == 1)
			{
				while(verify_finger(x) == 0);
				set_pass(x);			  
				confirm_pass(x);
				break;
			}
			else if(x == 2)
			{
				while(verify_id() == 0);
				while(verify_pass() == 0);
				edit_finger();
				break;
			}
			else if(x == 3)
			{
				CmdLCD(0x01);
				break;
			}
			else
			{
				display_warning();
				delay_ms(1000);				
			}
		}
		flag1 = 0;
	}
}
void Register()
{
	u32 k=0;
	set_id();
	set_pass(k);
	confirm_pass(k);
	while(enroll_finger() == 0);
	display_reg_success();
}
void login()
{
	u32 x=0;
	while(verify_id()==0);
	while(verify_pass()==0);
	while(verify_finger(x) == 0);
	delay_ms(100);
	display_login_success();
	delay_ms(100);
	opening_door();
	delay_ms(100);
	closing_door();
	delay_ms(100);
	motor_stop();
}
void entry()
{
	u8 ch;
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("1.REG   2.LOGIN");
	CmdLCD(0xc0);
	StrLCD("----WELCOME----");
	ch = ReadNUM();
	if(ch == 1)
		Register();
	else if(ch == 2)
		login();
	else
		return;
}

