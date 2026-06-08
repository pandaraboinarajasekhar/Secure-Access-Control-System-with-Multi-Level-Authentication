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
extern unsigned int idarr[10];
u8 buf2[5];
u8 buf3[5];

void init_idcount()
{
  //u32 i=0,x=0;
  idcount = i2c_eeprom_read(0x50,0x0000);
  if(idcount == 0xFF)
  {
  	idcount = 0;
  	i2c_eeprom_write(0x50,0x0000,0+48);
  }
  else
  {
  	idcount -= 48;
  }
/*  	CmdLCD(0x01);
	StrLCD("IDCOUNT : ");
	u32LCD(idcount);
	delay_ms(1000);
  for(i=0;i<idcount;i++)
  {
  	x = i2c_eeprom_read(0x50,0x0001+(i*6));
  	x = x-48;
	CmdLCD(0x01);
	StrLCD("ID : ");
	u32LCD(x);
	delay_ms(1000);
  }	*/
} 

void set_id()
{
	u32 i=0,x=0;
INPUT:
	display_enter_id();
	id = ReadNUM();
	u32LCD(id);
	delay_ms(500);
	for(i=0;i<idcount;i++)
	{
		x = i2c_eeprom_read(0x50,0x0001+(i*6));
		x = x-48;
		if(x == id)
		{
			display_id_existed();
			goto INPUT;
		}
	}

	i=id+48;
	i2c_eeprom_write(0x50,0x0001+(idcount*6),i);
	display_id_saved();
}
void set_pass(u32 k)
{
	u32 x = 5,i=0,y=0;              //  X = 5 TO HIDE PASS
INPUT:
	for(i=0;i<idcount;i++)
	{
		y = i2c_eeprom_read(0x50,0x0001+(i*6));
		y-=48;
		if(y == id)
			break;			
	}
	memset(buf2,'\0',5);
	display_enter_pass();
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
	if(k == 1)
	{
		sprintf((char *)buf2,"%d",pass);
		i2c_eeprom_page_write(0x50,0x0001+(i*6)+1,buf2,5);
	}
	else
	{
		sprintf((char *)buf2,"%d",pass);
		i2c_eeprom_page_write(0x50,0x0001+(idcount*6)+1,buf2,5);
	}		
}
int confirm_pass(u32 k)
{
	u32 x = 5,tp=0,i=0,y=0;
INPUT:
	for(i=0;i<idcount;i++)
	{
		y = i2c_eeprom_read(0x50,0x0001+(i*6));
		y-=48;
		if(y == id)
			break;			
	}
	memset(buf3,'\0',5);
	display_confirm_pass();
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
	if(k == 1)
	{
		i2c_eeprom_page_read(0x50,0x0001+(i*6)+1,buf3,5);
		sscanf((char *)buf3,"%d",&x);
		if(tp == x)
		{
			i2c_eeprom_page_write(0x50,0x0001+1+(i*6),buf2,5);
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
	else
	{
		i2c_eeprom_page_read(0x50,0x0001+(idcount*6)+1,buf3,5);
		sscanf((char *)buf3,"%d",&x);
		if(tp == x)
		{
			i2c_eeprom_page_write(0x50,0x0001+1+(idcount*6),buf2,5);
			display_pass_saved();
			idcount++;
			i2c_eeprom_write(0x50,0x0000,idcount+48);				
			return 1;
		}
		else
		{
			display_invalid_pass();
			x=5;
			goto INPUT;
		}
	}
}

int verify_id()
{
	u32 tid =0,x=0,i=0;
	memset(buf3,'\0',5);
	display_enter_id();
	tid = ReadNUM();
	CmdLCD(0xc0);
	u32LCD(tid);
	delay_ms(500);
	for(i=0;i<idcount;i++)
	{
		x = i2c_eeprom_read(0x50,0x0001+(i*6));
		x-=48;
		if(tid == x)
		{
			id = x;
			i2c_eeprom_page_read(0x50,0x0001+1+(i*6),buf3,5);
			return 1;
		}
	}
	display_invalid_id();
	return 0;
}
int verify_pass()
{
	u32 x = 5,tp =0;
INPUT:
	display_enter_pass();
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
	sscanf((char *)buf3,"%d",&pass);
	if(tp == pass)
		return 1;
	else
	{
		display_invalid_pass();
		return 0;
	}

}
int verify_finger(u32 k)
{
	u32 i =0;
	s32 fpid=0,x=0;
	fpid= search_fp()-1;
	/*CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("id : ");
	u32LCD(id);
	CmdLCD(0xc0);
	StrLCD("fpid : ");
	u32LCD(fpid);	
	delay_ms(1000);*/
	if(k == 1)
	{
		for(i=0;i<idcount;i++)
		{
			x = i2c_eeprom_read(0x50,0x0001+(i*6));
			x = x-48;
			if(fpid == x)
			{
				id = fpid;
				return 1;
			}
		}
		display_fing_not_match();
		return 0;
	}
	if(id == fpid)
			return 1;
	else if(id != fpid && fpid>0)
	{
		display_fing_not_match();
		return 0;
	}
	return 0;
}
void edit_pass_fing()
{
	int x =0 ,k=1;
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
				while(verify_finger(k) == 0);
				set_pass(k);
				confirm_pass(k);
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
			else if(x != -1)
			{
				display_warning();
				delay_ms(1000);
			}
	}
}
void factory_reset(void)
{
	unsigned int addr;
	u32 x = 0;
	display_reset();
	x = ReadNUM();
	u32LCD(x);
	delay_ms(500);
	if(x == 1)
	{
		CmdLCD(0x01);
		CmdLCD(0x80);
		StrLCD("   CLEARING  ");
		CmdLCD(0xc0);
		StrLCD("AT24C256  DATA");    
		for(addr=0;addr<100;addr++)
		{
			i2c_eeprom_write(0x50,addr,0xFF);
			delay_ms(10);
		}
		display_eeprom_cleared();

		CmdLCD(0x01);
		CmdLCD(0x80);
		StrLCD("CLEARING R305..");    		
		delay_ms(1000);
		if(deleteall_fp()==0)
		{
			delay_ms(500);
			display_r305_cleared();
		}
		idcount=0;
		id=0;
		pass=0;

		CmdLCD(0x01);
		CmdLCD(0x80);
		StrLCD("RESET SUCCESS");
		delay_ms(1500);
	}
	else if(x == 2)
	{
		CmdLCD(0x01);
		CmdLCD(0x80);
		StrLCD("RESET FAILED");
		delay_ms(1500);
	}
	else		
		display_warning();
}
void edit_all()
{
	u32 x=0;
	if(flag1 == 1)
	{
		flag1 = 0;
		while(1)
		{
			display_edit_pass_fing_res();
			x = ReadNUM();
			if(x == 1)
				edit_pass_fing();
			else if(x == 2)
			{
				factory_reset();
				break;
			}
			else if(x == 3)
				return;
			else
				display_warning();
		}

	}
}
void Register()
{
	u32 k=0;
	if(idcount == 9)
	{
		CmdLCD(0x01);
		CmdLCD(0x80);
		StrLCD("MAX IDS REACHED");
		delay_ms(1000);
		return;
	}
	set_id();
	set_pass(k);
	confirm_pass(k);
	while(enroll_finger()==0);
	display_reg_success();
}
void login()
{
	u32 x = 0;
	while(verify_id()==0);
	while(verify_pass()==0);
	while(verify_finger(x) == 0);
	display_login_success();
	opening_door();
	doors_ready_to_close();
	closing_door();
	motor_stop();
}
void entry()
{
	u8 ch;
	delay_ms(1000);
	CmdLCD(0x01);
	CmdLCD(0x80);
    StrLCD("SECURE ACCESS");
	CmdLCD(0xc0);
	StrLCD("Control System");
	delay_ms(1000);
	CmdLCD(0x01);
	CmdLCD(0x80);
    StrLCD("With Multilevel");
	CmdLCD(0xc0);
	StrLCD("Authentication");
	delay_ms(1000);
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("1.Record 2.Sign");
	CmdLCD(0xc0);
	StrLCD("---- SECURE ----");
	ch = ReadNUM();
	if(ch == 1)
		Register();
	else if(ch == 2)
		login();
	else
		return;
}
