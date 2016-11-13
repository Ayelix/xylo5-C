/**
 * \brief GPIO pin definitions and access functions.
 */

#include <asf.h>

void gpio_init(void)
{
	// The ioport service must be initialized first
	ioport_init();

	// Output pin states are set before their direction so that they will
	// start out in a known safe state.

	// Init the LED-related pins
	LEDS_DISABLE();
	ioport_set_pin_dir(ALL_LEDS_PIN, IOPORT_DIR_OUTPUT);
	RED_OFF();
	ioport_set_pin_dir(RED_PIN, IOPORT_DIR_OUTPUT);
	GREEN_OFF();
	ioport_set_pin_dir(GREEN_PIN, IOPORT_DIR_OUTPUT);
	BLUE_OFF();
	ioport_set_pin_dir(BLUE_PIN, IOPORT_DIR_OUTPUT);

	// Init the test point in case we want to use it for debugging
	TP1_LOW();
	ioport_set_pin_dir(TP1_PIN, IOPORT_DIR_OUTPUT);
}