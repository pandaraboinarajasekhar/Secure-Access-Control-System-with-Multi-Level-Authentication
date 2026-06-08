#include "type.h"
#include "interrupt_defines.h"
#include<lpc21xx.h>
#include "interrupt.h"

extern u32 flag1;
void InitINTERUPT()
{
	PINSEL0 = PINSEL0&~(3<<EINT2);
	PINSEL0 |= EINT2_INPUT_PIN;
	VICIntEnable = 1<<EINT2_CHNO;
	VICVectCntl1 = (1<<5)|EINT2_CHNO;
	VICVectAddr1 = (u32)eint2_irq;
}
void eint2_irq(void) __irq			 
{
	flag1=1;
	EXTINT = 1<<2;
	VICVectAddr = 0;
}

