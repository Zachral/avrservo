#ifndef _BUTTON_H__
#define _BUTTON_H__
#include <avr/io.h> 

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 
#define BUTTON_PIN 2
#define BUTTON_IS_CLICKED(PINC, BUTTON_PIN) !BIT_CHECK(PINC, BUTTON_PIN)
#define DEBOUNCE_DELAY_MS 100


void buttonClick(volatile bool *buttonWasPressed);
void button_init();
#endif