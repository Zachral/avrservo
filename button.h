#ifndef _BUTTON_H__
#define _BUTTON_H__
#include <avr/io.h> 

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 
#define BUTTON_IS_CLICKED(PINC, BUTTON_PIN) !BIT_CHECK(PINC, BUTTON_PIN)

/* Defines common macro*/
#define CON_CAT(a,b)                a ## b
#define DDR_(name)        CON_CAT(DDR,name)
#define PORT_(name)       CON_CAT(PORT,name)
#define PIN_(name)        CON_CAT(PIN,name)

#define BUTTON_PORT_INDEX   D
#define BUTTON_PIN 7
#define BUTTON_PORT_DIRECTION DDR_(BUTTON_PORT_INDEX)
#define BUTTON_PORT PORT_(BUTTON_PORT_INDEX)
#define BUTTON_PIN_INPUT PIN_(BUTTON_PORT_INDEX)

#define DEBOUNCE_DELAY_MS 100


void buttonClick(volatile bool *buttonWasPressed);
void button_init();
#endif