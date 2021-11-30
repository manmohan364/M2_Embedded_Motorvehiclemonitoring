#include "activity2.h"
#include "activity3.h"

void adc_initialization()
{
    ADMUX=(1<<REFS0);  
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

uint16_t adc_sense(uint8_t channel)
{
   
    ADMUX&=0xf8;
    channel=channel&0b00000111;
    ADMUX|=channel;

    ADCSRA|=(1<<ADSC);


    while(!(ADCSRA & (1<<ADIF)));
t
    ADCSRA|=(1<<ADIF);
    return(ADC);
}

void timer_initialization(void){

    TIMER1_FAST_PWM; 
    TIMER_PRESCALER_AS_64; 
    PWM_OUTPUT_PIN; 

}

void pwm_out(uint16_t ADC_READING){
    char Temp[20];
    char start[]="Temperature :)";

    if(ADC_READING>0 && ADC_READING<=200){

        OCR1A = 195; 
        Temp[0] = '2';
        Temp[1] = '0';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=210) && (ADC_READING<=500)){

        OCR1A = 495;
        Temp[0] = '2';
        Temp[1] = '5';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=501) && (ADC_READING<=700)){

        OCR1A = 695;
        Temp[0] = '2';
        Temp[1] = '9';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }
    else if((ADC_READING>=701) && (ADC_READING<=1024)){

        OCR1A = 1019; 
        Temp[0] = '3';
        Temp[1] = '3';
        Temp[2] = 223;
        Temp[3] = 'C';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }
    else{
        OCR1A = 0;
        Temp[0] = 'O';
        Temp[1] = 'F';
        Temp[2] = 'F';
        Temp[3] = ' ';
        Temp[4] = ' ';
        Temp[5] = '\0';
        LCD_String(start);
        LCD_Command(0xC0);
        LCD_String(Temp);
        _delay_ms(20);
    }

}