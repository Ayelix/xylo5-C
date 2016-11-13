/**
 * \brief GPIO pin definitions and access functions.
 */

#ifndef GPIO_H
#define GPIO_H

#include <asf.h>

/// Red channel control pin definition (active high)
#define RED_PIN			IOPORT_CREATE_PIN(PORTB, 6)
#define RED_OFF()		{ioport_set_pin_low(RED_PIN);}
#define RED_ON()		{ioport_set_pin_high(RED_PIN);}
#define RED_TOGGLE()	{ioport_toggle_pin(RED_PIN);}
/// Green channel control pin defintion (active high)
#define GREEN_PIN		IOPORT_CREATE_PIN(PORTC, 3)
#define GREEN_OFF()		{ioport_set_pin_low(GREEN_PIN);}
#define GREEN_ON()		{ioport_set_pin_high(GREEN_PIN);}
#define GREEN_TOGGLE()	{ioport_toggle_pin(GREEN_PIN);}
/// Blue channel control pin definition (active high)
#define BLUE_PIN		IOPORT_CREATE_PIN(PORTB, 7)
#define BLUE_OFF()		{ioport_set_pin_low(BLUE_PIN);}
#define BLUE_ON()		{ioport_set_pin_high(BLUE_PIN);}
#define BLUE_TOGGLE()	{ioport_toggle_pin(BLUE_PIN);}

/// All-LED control pin definition (active high)
#define ALL_LEDS_PIN	IOPORT_CREATE_PIN(PORTD, 3)
#define LEDS_DISABLE()	{ioport_set_pin_low(ALL_LEDS_PIN);}
#define LEDS_ENABLE()	{ioport_set_pin_high(ALL_LEDS_PIN);}
#define LEDS_TOGGLE()	{ioport_toggle_pin(ALL_LEDS_PIN);}

/// TP1 pin definition
#define TP1_PIN			IOPORT_CREATE_PIN(PORTD, 5)
#define TP1_LOW()		{ioport_set_pin_low(TP1_PIN);}
#define TP1_HIGH()		{ioport_set_pin_high(TP1_PIN);}
#define TP1_TOGGLE()	{ioport_toggle_pin(TP1_PIN);}

/// Initialize all GPIO pins
void gpio_init(void);

#endif // GPIO_H
