#include<lpc21xx.h>
#include "kpmDefines.h"
#include "type.h"
#include "lcd.h"
#include "delay.h"
//#include "interupt.h"
#include<stdlib.h>
extern int flag1;
/*u8 kpmLUT[4][4]={{'7','8','9','/'},
				 {'4','5','6','*'},
				 {'1','2','3','-'},
				 {'C','0','=','+'}};*/

u8 kpmLUT[4][4]={{'1','2','3','1'},
				 {'4','5','6','*'},
				 {'7','8','9','-'},
				 {'C','0','=','+'}};

void InitKPM()
{
	IODIR1 |= 0XF<<ROW0;
}

s32 colScan()
{
	if(flag1 == 1)
	{
		flag1 = 0;
		return -1;
	}
	else if(((IOPIN1>>COL0)&0XF)<15)
		return 0;
	else
		return 1;
 }
u32 rowCheck()
{
	u32 rno;
	for(rno=0;rno<4;rno++)
	{
		IOPIN1 = (IOPIN1 & ~(0xF << ROW0)) | ((~(1 << rno) << ROW0) & (0xF << ROW0));
		if(colScan()==0)
			break;
	}
	IOCLR1 = 0XF<<ROW0;
	return rno;
}

u32 colCheck()
{
	int cno;
	for(cno=0;cno<4;cno++)
	{
		if(((IOPIN1>>(COL0+cno))&1)==0)
			break;
	}
	return cno;
}


s8  keyscan()
{
	u32 rno,cno,keyVal;
	s32 rval;
	FUN:
	rval = colScan();
	while(rval)
	{
		if(rval == -1)
			return ((char)-1);
		goto FUN;
	}
//	while(colScan());
	rno = rowCheck();
	cno = colCheck();
	keyVal=kpmLUT[rno][cno];
	while(!colScan());
	return keyVal;
}

s32 ReadNUM()
{
	s8 key;
	key=keyscan();
	delay_ms(200);
	if(key>='0' && key<='9')
	{
		key-=48;
		return(key);
	}
	else if(key == (char)-1)
		return -1; 
	return 0;
}
u8 CGROMLUT[] = {0x00,0x00,0x0E,0X11,0X1F,0X15,0X1F,0X00,
		  		 0x00,0x0E,0x11,0X10,0X1F,0X15,0X1F,0X00};
u32 ReadNUMWithDisp(u32 *k)
{
	u32 sum = 0;
	s32 c = 0;
	u8 key = 0;
	u32 hide = 0;
	int i = 0;	
	BuildCGRAM(CGROMLUT,16);
	//*k = 0;   // k = input status flag
	/*
	 * k meaning:
	 * k = 0 ? valid input
	 * k = 1 ? no input entered
	 * k = 2 ? wrong key pressed (not '=' after input)
	 */
	CmdLCD(0xc0+15);
	CharLCD(0);
	while(1)
	{
		key = keyscan();
		delay_ms(100);
		if(key>='0' && key<='9')   // If digit pressed
		{
			CmdLCD(0xc0+c);
			CharLCD(key);
			delay_ms(200);
			if(*k == 5 && !hide)
			{
				CmdLCD(0xc0+c);
				CharLCD('*');
			}
			sum = sum*10 + (key-48); // Build number
			c++;
		}
		else if(key == '=' && c)   // End of input
		{
			if(c<4 && *k==5)
			{
				*k=3;
				break;
			}
			else
				break;
		}
		else if(key == 'C' && c)   // Backspace operation
		{
			sum /= 10;
			CmdLCD(0xc0+c-1);
			CharLCD(' ');
			
			if(c == 1)
				CmdLCD(0xc0);
			--c;
			CmdLCD(0xc0+c);
		}
		else if(key == '-' && c)
		{
			hide = 1;
			CmdLCD(0xc0+15);
		        CharLCD(1);
			CmdLCD(0xc0);
			u32LCD(sum);
		} 
		else if(key == '+' && c)
		{
			for(i = c-1;i>=0;--i)
			{
				CmdLCD(0xc0+i);
				CharLCD(' ');
			}
			sum = 0;
			c = 0;
			CmdLCD(0xc0);
		}	   
		else   // Invalid or empty input
		{
			if(c)
			{
				*k = 2;   // Wrong input method
				return 0;
			}
			*k = 1;       // No input entered
			return 0;
		}
		if(c == 4)
			break;
	}
	return sum;   // Return valid number
}
