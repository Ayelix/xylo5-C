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
	// TODO implement watchdog.
	wdt_disable();

	gpio_init();
}
