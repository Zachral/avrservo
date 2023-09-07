#include <avr/io.h>
#include "button.h"

void button_init(){
    BIT_CLEAR(DDRB,BUTTON_PIN);
    BIT_SET(PINB, BUTTON_PIN); 
    return; 
}

uint8_t poll_btn(uint8_t number) {
	static uint8_t integrator;
	static uint8_t output;

	switch(number) {
		case 0 :
			// Poll and integrate fire and set buttons
			if ((BTNPORT & (1<<BUTTON_PIN))) {
				if (integrator > 0) {
					integrator--;
				}
			} else if (integrator < DEBOUNCECYCLES) {
				integrator++;
			}
			return(0);

		case 1 :
			// If integrator is at threshhold, return 1
			// If integrator is at 0, return 0
			if (integrator == 0) {
				output = 0;
			}
			else if (integrator >= DEBOUNCECYCLES) {
				integrator = DEBOUNCECYCLES;
				output = 1;
			}
			return(output);
	}
	return(0);
}