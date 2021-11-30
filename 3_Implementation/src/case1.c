#include "activity1.h"

void seat_sensing(){
    DDRD|=(1<<PD2); //Set D2= 1
    DDRD&=~(1<<PD3); //Clear bit
    PORTD|=(1<<PD3); //Set bit
    DDRD&=~(1<<PD4); //Clear bit
    PORTD|=(1<<PD4); //Set bit
}