#ifndef CASE1_H_INCLUDED
#define CASE1_H_INCLUDED

#include <avr/io.h>
#include<util/delay.h>

#define seat_sense !(PIND &(1<<PD3))
#define heater_set (PIND &(1<<PD4))
#define heater_clear PORTD&=~(1<<PD4)
#define led_set PORTD|=(1<<PD2)
#define led_clear PORTD &=~(1<<PD2)

void seat_sensing();

#endif
