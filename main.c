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

// // B (digital pin 8 to 13)
// // C (analog input pins)
// // D (digital pins 0 to 7)

static volatile bool buttonWasPressed = false; 
static volatile uint8_t overflowCount = 0;

ISR(TIMER2_OVF_vect){
    overflowCount++;
    if(overflowCount > 200) // 80 amounts to 3,2 seconds 
        overflowCount = 0; 
}

ISR(TIMER2_COMPB_vect){
    //62 overflow flags amounts to one check every 0,99 seconds with the prescaler defined. 
    if(overflowCount > 62)
        buttonClick(&buttonWasPressed); 
 }

int main(void){
    sei();
    init_servo();
    button_init(); 
    init_serial();
    
  
   while(1){
        while (buttonWasPressed) {
            servo1_set_percentage(-30);
            servo2_set_percentage(60); 
        }
    }
    return 0;
}
