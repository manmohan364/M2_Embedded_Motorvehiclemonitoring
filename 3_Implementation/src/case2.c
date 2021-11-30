#include "case2.h"

void LCD_Command( unsigned char cmnd )
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0); 
	LCD_Port &= ~ (1<<RS);		
	LCD_Port |= (1<<EN);		
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4); 
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}


void LCD_Char( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0); 
	LCD_Port |= (1<<RS);	
	LCD_Port|= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (data << 4); 
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

void lcd_initialization (void)		
{
	LCD_Dir = 0xFF;			
	_delay_ms(20);			

	LCD_Command(0x02);		
	LCD_Command(0x28);             
	LCD_Command(0x0c);             
	LCD_Command(0x06);              
	LCD_Command(0x01);             
	_delay_ms(2);
}

void LCD_String (char *str)		
{
	int i;
	for(i=0;str[i]!=0;i++)		
	{
		LCD_Char (str[i]);
	}
}

void LCD_String_xy (char row, char pos, char *str)	
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	
	LCD_String(str);		
}

void lcd_off()
{
	LCD_Command (0x01);	
	_delay_ms(20);
	LCD_Command (0x80);		
}
