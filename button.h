#ifndef _BUTTON_H__
#define _BUTTON_H__
#include <avr/io.h> 
#include <stdbool.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 


#define CON_CAT(a,b)                a ## b
#define DDR_(name)        CON_CAT(DDR,name)
#define PORT_(name)       CON_CAT(PORT,name)
#define PIN_(name)        CON_CAT(PIN,name)


#define BUTTON_PORT_INDEX       D
#define BUTTON_PORT_DIRECTION   DDR_(BUTTON_PORT_INDEX)
#define BUTTON_PORT             PORT_(BUTTON_PORT_INDEX)
#define BUTTON_INPUT_PIN        PIN_(BUTTON_PORT_INDEX)
#define BUTTON_PIN              7

#define BUTTON_IS_CLICKED(BUTTON_INPUT_PIN, BUTTON_PIN) !BIT_CHECK(BUTTON_INPUT_PIN, BUTTON_PIN)
#define DEBOUNCE_DELAY_MS 300


void buttonClick(volatile bool *buttonWasPressed);
void button_init();
#endif