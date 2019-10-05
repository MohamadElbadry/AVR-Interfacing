
#ifndef LCD_H_
#define LCD_H_

void Lcd_Init(void);
void Lcd_SendChar(u8 Char);
void Lcd_SendCommand(u8 Command);
void Lcd_WritePattern(u8 address , u8 *pattern);
void Lcd_SendString(u8 *ptr) ;
void Lcd_CheckAC(void);
#define Return_Home     0x02
#define DISPLAY_CLEAR   0x01
#define MoveToRight     0x14
#define MoveToLeft      0x10
#define Shift_DataRight 0x1C
#define Shift_DataLeft  0x18

#endif /* LCD_H_ */
