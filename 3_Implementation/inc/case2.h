#ifndef CASE2_H_INCLUDED
#define CASE2_H_INCLUDED

#include <avr/io.h>		
#include <util/delay.h>		
#define LCD_Dir  DDRB			
#define EN PB3 				

void LCD_Command( unsigned char cmnd );
void LCD_Char( unsigned char data );
void lcd_initialization (void);
void LCD_String (char *str);
void LCD_String_xy (char row, char pos, char *str);
void lcd_off();

#endif
