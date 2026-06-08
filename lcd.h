#include "type.h"
void WriteLCD(u8 data);
void CmdLCD(u8 cmd);
void CharLCD(u8 ascii);
void InitLCD(void);
void StrLCD(u8 *str);
//void BuildCGram(u8 *ptr,u32 n);
s32 checkPalindrome(u8 *str);
char *Word_1st_letter_upper(char *str);
void u32LCD(u32 data);
void BuildCGRAM(u8 *ptr,u32 n);
