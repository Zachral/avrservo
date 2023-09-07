#ifndef _BUTTON_H__
#define _BUTTON_H__
#include <avr/io.h> 

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

#define BTNPORT PINB
#define BUTTON_PIN 13

void button_init();
uint8_t poll_btn(uint8_t number); 
#endif