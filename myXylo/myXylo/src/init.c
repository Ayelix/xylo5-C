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
#include "leds.h"

void board_init(void)
{
	// TODO implement watchdog.
	wdt_disable();

	// All modules might use GPIO so init it first
	gpio_init();

	leds_init();

	// Module initialization is complete and everyone should be ready for their
	// interrupts to start coming in.  Enable interrupts.
	sei();
}
