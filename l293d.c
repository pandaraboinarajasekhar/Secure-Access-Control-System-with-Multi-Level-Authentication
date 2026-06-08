#include<lpc21xx.h>
#include "delay.h"
#include "lcd.h"
#define M1 20
#define M2 21
#define BUZZ 22
u8 CGRAMLUT[] = {0x00,0x00,0x0E,0X11,0X1F,0X15,0X1F,0X00,
				 0x00,0x0E,0x11,0X10,0X1F,0X15,0X1F,0X00,
				 0xFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,};

void init_l293d(void)
{
        IODIR0 |= ((1<<M1)|(1<<M2)|(1<<BUZZ));
}
void opening_door(void)
{
	s32 i=0,j=0,a=0;
	BuildCGRAM(CGRAMLUT,32);
	CmdLCD(0x80);
	StrLCD("DOORS OPENING..");
	IOSET0 = 1<<M1;
	IOCLR0 = 1<<M2;
	for(i=0;i<=7;i++)
	{
		CmdLCD(0xc0);
		for(j=-7;j<=7;j++)
		{
			(j<0)?(a=-j):(a=j);
			if(a>=i)
				CharLCD(2);
			else
				CharLCD(32);
		}
		delay_ms(1000);
	}
	CmdLCD(0xc0);
	StrLCD("                ");
	IOCLR0 = (1<<M1) | (1<<M2);
}
void closing_door()
{
	s32 i=0,j=0,a=0;
	BuildCGRAM(CGRAMLUT,32);
	CmdLCD(0x80);
	StrLCD("DOORS CLOSING..");
	IOCLR0 = 1<<M1;
	IOSET0 = 1<<M2;
	for(i=7;i>=0;i--)
	{
		CmdLCD(0xc0);
		for(j=-7;j<=7;j++)
		{
			(j<0)?(a=-j):(a=j);
			if(a>=i)
				CharLCD(2);
			else
				CharLCD(32);
		}
		delay_ms(1000);
	}
	CmdLCD(0xc0);
	StrLCD("                ");	
    IOCLR0 = (1<<M1) | (1<<M2);
}

void motor_stop(void)
{
    CmdLCD(0x01);
    CmdLCD(0x80);
    StrLCD("MOTOR STOPPED");
    IOCLR0 = (1<<M1) | (1<<M2);
    delay_s(1);
}

void doors_ready_to_close()
{
	u32 i=0;
	for(i=0;i<5;i++)
	{
		CmdLCD(0x01);
		CmdLCD(0x80);
		StrLCD("  DOORS READY  "); 
		CmdLCD(0xc0);
		StrLCD("   TO CLOSE   ");
		IOSET0 = 1<<BUZZ;
		delay_ms(1000);
		CmdLCD(0x80);
		StrLCD("                "); 
		CmdLCD(0xc0);
		StrLCD("                ");
		IOCLR0 = 1<<BUZZ;
		delay_ms(200);
	}
}

