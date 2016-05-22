/*
    Author:		Arpah Halder, Department of Mining Engineering, IIT Kharagpur
	Email:		tech.halder.arpan@gmail.com
	Date:		21-05-2016
	Project:	TeleMonitor
 	Version:	v1.0
	
	Inspired by Eric Conner's ATmega32 for Arduino IDE project
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NOT_ON_TIMER 0
#define TIMER0A 1
#define TIMER0B 2
#define TIMER1A 3
#define TIMER1B 4
#define TIMER2  5

#undef TCCR2A

#define NOT_A_PORT 0
#define NOT_ON_TIMER 0

/*			
		                                  ATMEL ATmega16-32			
					
                                      + - - U - - +                                  
            GPIO  12    PB  0     1   |           |   40    PA  0   ADC 0   GPIO  20
            GPIO  13    PB  1     2   |           |   39    PA  1   ADC 1   GPIO  21
            GPIO  14    PB  2     3   |           |   38    PA  2   ADC 2   GPIO  22
            GPIO  15    PB  3     4   |           |   37    PA  3   ADC 3   GPIO  23
    SS      GPIO  16    PB  4     5   |           |   36    PA  4   ADC 4   GPIO  24
  MOSI      GPIO  17    PB  5     6   |           |   35    PA  5   ADC 5   GPIO  25
  MISO      GPIO  18    PB  6     7   |           |   34    PA  6   ADC 6   GPIO  26
   SCK      GPIO  19    PB  7     8   |           |   33    PA  7   ADC 7   GPIO  27
 RESET                            9   |           |   32            AREF             
   VCC                           10   |           |   31            GND              
   GND                           11   |           |   30            AVCC             
 XTAL2                           12   |           |   29    PC  7           GPIO  11
 XTAL1                           13   |           |   28    PC  6           GPIO  10
   RXD                  PD  0    14   |           |   27    PC  5           GPIO  9
   TXD                  PD  1    15   |           |   26    PC  4           GPIO  8
            GPIO  1     PD  2    16   |           |   25    PC  3           GPIO  7
            GPIO  2     PD  3    17   |           |   24    PC  2           GPIO  6
            GPIO  3     PD  4    18   |           |   23    PC  1   SDA     GPIO  28
            GPIO  4     PD  5    19   |           |   22    PC  0   SCL     GPIO  29
            GPIO  5     PD  6    20   |           |   21    PD  7   RS-485  GPIO  30
                                      + - - - - - +                        
*/			


const static uint8_t SDA = 28;
const static uint8_t SCL = 29;

const static uint8_t SS   = 16;
const static uint8_t MOSI = 17;
const static uint8_t MISO = 18;
const static uint8_t SCK  = 19;

static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;
static const uint8_t A6 = 6;
static const uint8_t A7 = 7;

#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  ((p < 8) ? (p) + 24 : -1)//TODO : MAPPING
#define digitalPinHasPWM(p)         ((p) == 4 || (p) == 5 || (p) == 7) //TODO: MPPING

#ifdef ARDUINO_MAIN

const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
	NOT_A_PORT,
	NOT_A_PORT,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	NOT_A_PORT,
	NOT_A_PORT,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
	NOT_A_PORT,
	NOT_A_PORT,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[30] = {
PD	,	 	 //	 	PD	2	 	>>>	GPIO		1
PD	,	 	 //	 	PD	3	 	>>>	GPIO		2
PD	,	 	 //	 	PD	4	 	>>>	GPIO		3
PD	,	 	 //	 	PD	5	 	>>>	GPIO		4
PD	,	 	 //	 	PD	6	 	>>>	GPIO		5
PC	,	 	 //	 	PC	2	 	>>>	GPIO		6
PC	,	 	 //	 	PC	3	 	>>>	GPIO		7
PC	,	 	 //	 	PC	4	 	>>>	GPIO		8
PC	,	 	 //	 	PC	5	 	>>>	GPIO		9
PC	,	 	 //	 	PC	6	 	>>>	GPIO	 10
PC	,	 	 //	 	PC	7	 	>>>	GPIO		11
PB	,	 	 //	 	PB	0	 	>>>	GPIO 	12
PB	,	 	 //	 	PB	1	 	>>>	GPIO 	13
PB	,	 	 //	 	PB	2	 	>>>	GPIO 	14
PB	,	 	 //	 	PB	3	 	>>>	GPIO 	15
PB	,	 	 //	 	PB	4	 	>>>	GPIO		16
PB	,	 	 //	 	PB	5	 	>>>	GPIO		17
PB	,	 	 //	 	PB	6	 	>>>	GPIO		18
PB	,	 	 //	 	PB	7	 	>>>	GPIO		19
PA	,	 	 //	 	PA	0	 	>>>	GPIO		20
PA	,	 	 //	 	PA	1	 	>>>	GPIO		21
PA	,	 	 //	 	PA	2	 	>>>	GPIO		22
PA	,	 	 //	 	PA	3	 	>>>	GPIO		23
PA	,	 	 //	 	PA	4	 	>>>	GPIO		24
PA	,	 	 //	 	PA	5	 	>>>	GPIO		25
PA	,	 	 //	 	PA	6	 	>>>	GPIO		26
PA	,	 	 //	 	PA	7	 	>>>	GPIO		27
PC	,	 	 //	 	PC	1	 	>>>	GPIO		28
PC	,	 	 //	 	PC	0	 	>>>	GPIO		29
PD	,	 	 //	 	PD	7	 	>>>	GPIO		30
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[30] = {	
_BV(	2	)	,	 	 //	 	PD	2	 	>>>	GPIO		1
_BV(	3	)	,	 	 //	 	PD	3	 	>>>	GPIO		2
_BV(	4	)	,	 	 //	 	PD	4	 	>>>	GPIO		3
_BV(	5	)	,	 	 //	 	PD	5	 	>>>	GPIO		4
_BV(	6	)	,	 	 //	 	PD	6	 	>>>	GPIO		5
_BV(	2	)	,	 	 //	 	PC	2	 	>>>	GPIO		6
_BV(	3	)	,	 	 //	 	PC	3	 	>>>	GPIO		7
_BV(	4	)	,	 	 //	 	PC	4	 	>>>	GPIO		8
_BV(	5	)	,	 	 //	 	PC	5	 	>>>	GPIO		9
_BV(	6	)	,	 	 //	 	PC	6	 	>>>	GPIO	 10
_BV(	7	)	,	 	 //	 	PC	7	 	>>>	GPIO	 11
_BV(	0	)	,	 	 //	 	PB	0	 	>>>	GPIO	 12
_BV(	1	)	,	 	 //	 	PB	1	 	>>>	GPIO	 13
_BV(	2	)	,	 	 //	 	PB	2	 	>>>	GPIO	 14
_BV(	3	)	,	 	 //	 	PB	3	 	>>>	GPIO	 15
_BV(	4	)	,	 	 //	 	PB	4	 	>>>	GPIO	 16
_BV(	5	)	,	 	 //	 	PB	5	 	>>>	GPIO	 17
_BV(	6	)	,	 	 //	 	PB	6	 	>>>	GPIO	 18
_BV(	7	)	,	 	 //	 	PB	7	 	>>>	GPIO	 19
_BV(	0	)	,	 	 //	 	PA	0	 	>>>	GPIO	 20
_BV(	1	)	,	 	 //	 	PA	1	 	>>>	GPIO	 21
_BV(	2	)	,	 	 //	 	PA	2	 	>>>	GPIO	 22
_BV(	3	)	,	 	 //	 	PA	3	 	>>>	GPIO	 23
_BV(	4	)	,	 	 //	 	PA	4	 	>>>	GPIO	 24
_BV(	5	)	,	 	 //	 	PA	5	 	>>>	GPIO	 25
_BV(	6	)	,	 	 //	 	PA	6	 	>>>	GPIO	 26
_BV(	7	)	,	 	 //	 	PA	7	 	>>>	GPIO	 27
_BV(	1	)	,	 	 //	 	PC	1	 	>>>	GPIO	 28
_BV(	0	)	,	 	 //	 	PC	0	 	>>>	GPIO	 29
_BV(	7	)	,	 	 //	 	PD	7	 	>>>	GPIO	 30
};
//TODO: TIMER MAPPING
const uint8_t PROGMEM digital_pin_to_timer_PGM[32] = {
	NOT_ON_TIMER,  // PB0 ** D0
	NOT_ON_TIMER,  // PB1 ** D1
	NOT_ON_TIMER,  // PB2 ** D2
	TIMER0A,	   // PB3 ** D3
	NOT_ON_TIMER,  // PB4 ** D4
	NOT_ON_TIMER,  // PB5 ** D5
	NOT_ON_TIMER,  // PB6 ** D6
	NOT_ON_TIMER,  // PB7 ** D7
	NOT_ON_TIMER,  // PD0 ** D8
	NOT_ON_TIMER,  // PD1 ** D9
	NOT_ON_TIMER,  // PD2 ** D10
	NOT_ON_TIMER,  // PD3 ** D11
	TIMER1B,	   // PD4 ** D12
	TIMER1A,	   // PD5 ** D13
	NOT_ON_TIMER,  // PD6 ** D14
	TIMER2,		   // PD7 ** D15
	NOT_ON_TIMER,  // PC0 ** D16
	NOT_ON_TIMER,  // PC1 ** D17
	NOT_ON_TIMER,  // PC2 ** D18
	NOT_ON_TIMER,  // PC3 ** D19
	NOT_ON_TIMER,  // PC4 ** D20
	NOT_ON_TIMER,  // PC5 ** D21
	NOT_ON_TIMER,  // PC6 ** D22
	NOT_ON_TIMER,  // PC7 ** D23
	NOT_ON_TIMER,  // PA7 ** A0 D24
	NOT_ON_TIMER,  // PA6 ** A1 D25
	NOT_ON_TIMER,  // PA5 ** A2 D26
	NOT_ON_TIMER,  // PA4 ** A3 D27
	NOT_ON_TIMER,  // PA3 ** A4 D28
	NOT_ON_TIMER,  // PA2 ** A5 D29
	NOT_ON_TIMER,  // PA1 ** A6 D30
	NOT_ON_TIMER,  // PA0 ** A7 D31
};

#endif
#endif
