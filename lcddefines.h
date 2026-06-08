#include "type.h"
#define _8_BIT_LINE1 0X30
#define _8_BIT_LINE2 0X38
#define DISP_ON 0X0C
#define DISP_CUR_ON 0X0E
#define DISP_CUR_BLINK_ON 0X0F
#define CLEAR_LCD 0X01
#define CUR_SHIFT_RIGHT 0X06
#define GOTO_CGRAM 0X40

#define LCD 8
#define RS 16
#define RW 18
#define EN 17

/*void StrLCD(u8 *str);
void BuildCGram(u8 *ptr,u32 n);
void InitLCD(void);
void CmdLCD(u8 cmd);
void WriteLCD(u8 data);
void CharLCD(u8);
s32 checkPalindrome(u8 *str);
char *Word_1st_letter_upper(char *str);
void u32LCD(u32); */
