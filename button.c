#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include "button.h"

void button_init(){

	TCCR2A = 0; 
	TCCR2B = (1<<CS20) | (1<<CS21) | (1<<CS22); 
	OCR2B = 250; 
	TIMSK2 = (1<<OCIE2B); 
    BIT_CLEAR(DDRD,BUTTON_PIN);
    BIT_SET(PORTD, BUTTON_PIN); 
    return; 
}

void buttonClick(volatile bool *buttonWasPressed){
	printf("IM in!\n");
	 if (BUTTON_IS_CLICKED(PIND,BUTTON_PIN)) {
		// Button press detected, wait for debouncing
		_delay_ms(DEBOUNCE_DELAY_MS);
		
		// Check the button state again after debouncing
		if (BUTTON_IS_CLICKED(PIND, BUTTON_PIN)) {
			*buttonWasPressed = true; 
			}
		}
	return; 
}