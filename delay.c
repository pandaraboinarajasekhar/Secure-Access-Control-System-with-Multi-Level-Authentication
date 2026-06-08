#include "type.h"
void delay_us(u32 u)
{
	for(u*=12;u>0;--u);				  
}
void delay_ms(u32 m)
{
	for(m*=12000;m>0;--m);
}
void delay_s(u32 s)
{
	for(s*=12000000;s>0;--s);
}		
