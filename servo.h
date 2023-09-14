#ifndef _SERVO_H_
#define _SERVO_H_
#include "button.h" 
// These pins are available on the shield via the header:
//
//		Mega	Uno
// digital 5	PE3	PD5
// digital 6	PH3	PD6
// digital 9	PH6	PB1
// analog 5	PF5	PC5
 
// The settings below are for the Mega, modify
// in case you want to use other pins
#define SERVO_PORT_INDEX        D
#define SERVO_PORT              PORT_(SERVO_PORT_INDEX)
#define SERVO_PORT_DIRECTION    DDR_(SERVO_PORT_INDEX)
#define LEFT_SERVO_PIN          PD5
#define RIGHT_SERVO_PIN         PD6

// #define PORT_1	PORTD
// #define PIN_1	PD5
// #define DDR_1	DDRD
 
// #define PORT_2	PORTD
// #define PIN_2	PD6
// #define DDR_2	DDRD
 
void init_servo(void);
void servo1_set_percentage(signed char percentage);
void servo2_set_percentage(signed char percentage);
 
#endif /* _SERVO_H_ */