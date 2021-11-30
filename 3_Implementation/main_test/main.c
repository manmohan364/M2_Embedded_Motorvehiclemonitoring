#include <avr/io.h>
#include<util/delay.h>
#include "activity1.h"
#include "activity2.h"
#include"activity3.h"
int main()
{
    seat_sensing();
    adc_initialization();
    timer_initialization();
    lcd_initialization();			

    uint16_t temp_var;

	while(1)
    {
        if(seat_sense)
        {
            PORTD|=(1<<PD4);
            if(heater_set){
                led_set;
                _delay_ms(200);
                lcd_off();
                temp_var=adc_sense(2);
                pwm_out(temp_var);

            }
            else
                {
                    led_clear;
                     _delay_ms(200);
                    heater_clear;
                    _delay_ms(200);
                    lcd_off();
                }
        }
        else{
            led_clear;
            _delay_ms(200);
            heater_clear;
            _delay_ms(200);
            lcd_off();
        }
    }
    return 0;
}