#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include "uart.h"
#include "millis.h"
#include "servo.h"
#include "button.h"

#define DEBOUNCE_DELAY_MS 100
//https://wokwi.com/projects/364340216052770817
// void init_timer(){
//     TCCR0A = 0;
//     TCCR0B = 0;
//     TCNT0 = 0; 
//     TCCR0B |= 0b00000100; 
//     //TIMSK0 |= 0b00000010;
//     OCR0A = 312; 
// }

// // B (digital pin 8 to 13)
// // C (analog input pins)
// // D (digital pins 0 to 7)

// ISR(TIMER_COMPA_vect){
//     TCNT1 = 0; 
//     poll_btn(0);
// }

int main(void){
    init_servo();
    button_init(); 
    // init_timer(); 
    sei();
    bool buttonWasPressed = false; 
     while (1) {
        if (BUTTON_IS_CLICKED(PIND,BUTTON_PIN)) {
                // Button press detected, wait for debouncing
                _delay_ms(DEBOUNCE_DELAY_MS);
                
                // Check the button state again after debouncing
                if (BUTTON_IS_CLICKED(PIND, BUTTON_PIN)) {
                     buttonWasPressed = true;
                    }
                }

        while(buttonWasPressed){
            servo1_set_percentage(60);
            servo2_set_percentage(60); 
        }
    }
    return 0;
}
