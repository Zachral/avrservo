#ifndef _BUTTON_H__
#define _BUTTON_H__
#include <avr/io.h> 

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 
#define BTNPORT PIND
#define BUTTON_PIN 2
#define BUTTON_IS_CLICKED(PIND, BUTTON_PIN) !BIT_CHECK(PIND, BUTTON_PIN)
#define DEBOUNCE_CYCLES 5

void button_init();
uint8_t poll_btn(uint8_t number); 
#endif