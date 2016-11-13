/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>

#define delay1us nop
#define delay10us() { \
	delay1us(); delay1us(); delay1us(); delay1us(); delay1us(); \
	delay1us(); delay1us(); delay1us(); delay1us(); delay1us(); \
}
#define delay50us() { \
	delay10us(); delay10us(); delay10us(); delay10us(); delay10us(); \
}
#define delay100us() {delay50us(); delay50us(); }

static void delay250us(void) {delay100us(); delay100us(); delay50us();}

static void delay500ms(void)
{
	for (uint16_t i = 0; i < 2000; i++)
	{
		delay250us();
	}
}

#define RED_PULSE()		{RED_ON(); delay250us(); RED_OFF();}
#define BLUE_PULSE()	{BLUE_ON(); delay250us(); BLUE_OFF();}
#define GREEN_PULSE()	{GREEN_ON(); delay250us(); GREEN_OFF();}

int main (void)
{
	board_init();

	while (true)
	{
		TP1_TOGGLE();

		LEDS_ENABLE();

		for (uint8_t i = 0; i < 100; i++)
		{
			RED_PULSE();
			delay250us(); // keep green off this time
			delay250us(); // keep blue off this time
		}

		delay500ms();

		for (uint8_t i = 0; i < 100; i++)
		{
			delay250us(); // keep red off this time
			GREEN_PULSE();
			delay250us(); // keep blue off this time
		}

		delay500ms();

		for (uint8_t i = 0; i < 100; i++)
		{
			delay250us(); // keep red off this time
			delay250us(); // keep green off this time
			BLUE_PULSE();
		}

		LEDS_DISABLE();

		delay500ms();

	}
}
