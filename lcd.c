#include<lpc21xx.h>
#include<string.h>
#include<stdlib.h>
#include "delay.h"
#include "type.h"
#include "lcddefines.h"
void WriteLCD(u8 data)
{
	IOCLR0 = 1<<RW;	                      // RW=0 WRITE MODE 
	IOPIN0 =(IOPIN0 &~(0XFF<<LCD))|(data<<LCD);	  // WRITING DATA INTO REGISTERS
	IOSET0 = 1<<EN;
	delay_us(1);
	IOCLR0 = 1<<EN;
	delay_ms(2);
}
void CmdLCD(u8 cmd)
{
	IOCLR0 = 1<<RS;     //RS = 0 Command register selected
	WriteLCD(cmd);
}
void CharLCD(u8 ascii)
{
	IOSET0 = 1<<RS;
	WriteLCD(ascii);
}
void InitLCD(void)
{
	IODIR0 |= 0XFF<<LCD;
	IODIR0 |= 1<<RS;
	IODIR0 |= 1<<RW;
	IODIR0 |= 1<<EN;
	delay_ms(15);
	CmdLCD(_8_BIT_LINE1);
	delay_ms(5);
	CmdLCD(_8_BIT_LINE1);
	delay_us(100);
	CmdLCD(_8_BIT_LINE1);
	CmdLCD(_8_BIT_LINE2);
	//CmdLCD(DISP_CUR_BLINK_ON);
	CmdLCD(DISP_CUR_ON);
	CmdLCD(CLEAR_LCD);
	CmdLCD(CUR_SHIFT_RIGHT);
	CmdLCD(0x10);
}
void StrLCD(u8 *str)
{
	while(*str)
	{
		CharLCD(*str++);
	}
}
void BuildCGRAM(u8 *ptr,u32 n)
{
	s32 i;
	CmdLCD(GOTO_CGRAM);
	for(i=0;i<n;i++)
	{
		CharLCD(ptr[i]);
	}
	CmdLCD(0X80);
}

void u32LCD(u32 data)
{
	u8 arr[10];
	s32 i=0;
	if(data == 0)
		CharLCD('0');
	else
	{
		while(data)
		{
			arr[i++]=(data%10)+48;
			data/=10;
		}
		for(--i;i>=0;i--)
		{
			CharLCD(arr[i]);
		}
	}
}
