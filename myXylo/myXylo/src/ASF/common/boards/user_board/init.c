/**
 * \file
 *
 * \brief User board initialization template
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include <board.h>
#include <conf_board.h>
#include <avr/wdt.h>

void board_init(void)
{
	// Watchdog initialization.
	// TODO implement watchdog.
	wdt_disable();

	// GPIO initialization.  Output pin states are set before their direction
	// so that they will start out in a known safe state.

	ioport_init();

	LEDS_DISABLE();
	ioport_set_pin_dir(ALL_LEDS_PIN, IOPORT_DIR_OUTPUT);
	RED_OFF();
	ioport_set_pin_dir(RED_PIN, IOPORT_DIR_OUTPUT);
	GREEN_OFF();
	ioport_set_pin_dir(GREEN_PIN, IOPORT_DIR_OUTPUT);
	BLUE_OFF();
	ioport_set_pin_dir(BLUE_PIN, IOPORT_DIR_OUTPUT);

	TP1_LOW();
	ioport_set_pin_dir(TP1_PIN, IOPORT_DIR_OUTPUT);
}
