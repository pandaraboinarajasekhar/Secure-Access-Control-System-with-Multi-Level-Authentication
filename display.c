#include "lcd.h"
#include "delay.h"
static u8 CGRAMLUT[] = {0x00,0x00,0x0E,0X11,0X1F,0X15,0X1F,0X00,
	       	 0x00,0x0E,0x11,0X10,0X1F,0X15,0X1F,0X00,
		 0xFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,};

void displayfingerinfo()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("1.ENROL 2.SEARCH");
	CmdLCD(0xc0);
	StrLCD("3.DELETE 4.EXIT");
}
void display_empty()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("NO DATA ENTERED");
	CmdLCD(0xc0);
	StrLCD("ENTER DATA");
	delay_ms(1000); 
}
void display_input_format()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("ENTER DATA THEN");
	CmdLCD(0xc0);
	StrLCD("PRESS '='");
	delay_ms(1000);	
}
void display_warning()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("INVALID...!");
	delay_ms(1000);
}
void display_pass_len()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("PASSWORD LENGTH");
	CmdLCD(0xc0);
	StrLCD("SHOULD BE 4");
	delay_ms(1000);
}
void display_login_success()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("-SIGIN SUCCESS-");
	delay_ms(1000);	
	return;
}
void display_pass_saved()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("-SAVED PASSWORD-");
	delay_ms(1000);
}
void display_invalid_id()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("--INVALID ID--");
	delay_ms(1000);
}
void display_reg_success()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("  REGISTERED  ");
	CmdLCD(0xc0);
	StrLCD(" SUCCESSFULLY ");
	delay_ms(1000);
}
void display_edit_pass_fing_res()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("1.EDIT_PASS_FING");
	CmdLCD(0xc0);
	StrLCD("2.RESET  3.EXIT");
	delay_ms(1000);	
}
void display_r305_cleared()
{	
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("R305 CLEARED");
	delay_ms(1000);
}
void display_eeprom_cleared()
{	
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("AT24C256 CLEARED");
	delay_ms(1000);	
}
void display_reset()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("CLEAR DATA..?");
	CmdLCD(0xc0);
	StrLCD("1.YES 2.NO : ");
}
void display_fing_not_match()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("FING NOT MATCHED");
	CmdLCD(0xc0);
	StrLCD("   TRY AGAIN   ");
	delay_ms(1000);
}
void display_enter_id()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("ENTER ID [1-9]: ");
	CmdLCD(0xc0);
}
void display_id_existed()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("  ID  ALREADY  ");
	CmdLCD(0xc0);
	StrLCD("   	SAVED    ");
	delay_ms(1000);		
}  
void display_id_saved()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD(" --ID SAVED-- ");
	delay_ms(1000);
}
void display_enter_pass()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("ENTER PASSWORD:");
	CmdLCD(0xc0);
}
void display_confirm_pass()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("CONFIRM PASSWORD");
	CmdLCD(0xc0);
}
void display_invalid_pass()
{
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("INVALID PASSWORD");
	delay_ms(1000);
}
void display_loading()
{
	u32 i=0;
	BuildCGRAM(CGRAMLUT,24);
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("LOADING...");
	for(i=0;i<8;i++)
	{
		CmdLCD(0xc0+i*2);
		CharLCD(2);
		CmdLCD(0xc0+i*2+1);
		CharLCD(2);
		delay_ms(500);
	}
}
