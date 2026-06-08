#include "type.h"
#include "delay.h"
#include "lcd.h"
#include "kpm.h"
#include "R305.h"
#include "display.h"
extern unsigned int id;
unsigned int enroll_finger()
{
	if(enroll(id)==0)
		return 1;
	else
	{
		CmdLCD(0x01);
		CmdLCD(0x80);
		StrLCD(" ENROLL FAILED ");
		CmdLCD(0xc0);
		StrLCD("  TRY AGAIN   ");
		delay_ms(1500);
		return 0;
	}
}
void edit_finger()
{
	u32 choice=0;
	s32 x=0;
	while(1)
	{
		displayfingerinfo();
		choice = ReadNUM();
		if(choice == 1)
		{
			enroll_finger();
		}
		else if(choice == 2)
		{
	   		CmdLCD(0x01);
	   		CmdLCD(0x80);
	   		StrLCD("PLACE FINGER");
         	CmdLCD(0xC0);
			x = search_fp()-1;
			if(x != id && x>0)
			{
				CmdLCD(0x01);
	   			CmdLCD(0x80);
	   			StrLCD("  FINGER CAN'T  ");
				CmdLCD(0xc0); 
				StrLCD("     ACCESS    ");	
				delay_ms(1000);
			}
			else if(x>0)
			{
				StrLCD("FINGER ID : ");
          		u32LCD(x);  
				delay_ms(1500); 
			}
		}
		else if(choice == 3)
		{
			{
				if(delete_fp(id) == 0x00)
				{
					CmdLCD(0x01);
			   		CmdLCD(0x80);
			   		StrLCD("ID : ");
					u32LCD(id);	
					StrLCD(" DELETED");
					CmdLCD(0xc0);
					StrLCD(" SUCCESSFULLY ");				
					delay_ms(1000);
				}
				else
				{
					CmdLCD(0x01);
			   		CmdLCD(0x80);
			   		StrLCD("  FAILED TO  ");
					CmdLCD(0xc0);
					StrLCD("   DELETE  ");					
					delay_ms(1000);
				}
			}
		}
		else if(choice == 4)
		{
			CmdLCD(0x01);
			return;
		}	
		else
		{
			display_warning();
			delay_ms(1000);
		}
	}
}
