#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include "uart.h"
#include "millis.h"
#include "servo.h"
#include "button.h"

//https://wokwi.com/projects/364340216052770817
void init_timer(){
    T
}

// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)

int main(void){
    init_servo();
    button_init(); 
    sei();
    bool buttonIsClicked = false; 

    if(BIT_CHECK(PINB, BUTTON_PIN)){
        _delay_ms(50);
        buttonIsClicked != buttonIsClicked;   
    } 
    while(buttonIsClicked)
    {

    
    servo1_set_percentage(-20);
    servo2_set_percentage(100);

        // servo1_set_percentage(45);
        // _delay_ms(5000);



 
        // servo1_set_percentage(-100);
        // _delay_ms(1000);
    }
    return 0;
}
