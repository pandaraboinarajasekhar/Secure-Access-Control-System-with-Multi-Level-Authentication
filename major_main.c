#include<lpc21xx.h>
#include "lcd.h"
#include "R305.h"
#include "kpm.h"
#include "edit.h"
#include "uart0.h"
#include "interrupt.h"
#include "i2c.h"
#include "delay.h"
#include "l293d.h"
#include "i2c_eeprom.h"
#include "display.h"

volatile unsigned int idcount = 0;
volatile unsigned int pass = 0;
volatile unsigned int id = 0;
volatile unsigned int flag1 = 0;
volatile unsigned int flag2 = 0;
volatile unsigned int idarr[10];

int main()
{
	InitLCD();
	InitKPM();
	InitUART0();
	i2c_init();
	InitINTERUPT();
	init_l293d();
	init_idcount();
//	display_loading();
	while(1)
	{
		entry();
		edit_all();
	}		
}
