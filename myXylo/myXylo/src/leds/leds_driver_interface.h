/**
 * \brief Driver interface for the LEDs.
 * \details Functions/macros described here must be implemented in the file
 *		led_driver.h.  The expected signatures are given here for the items
 *		which are expected to be implemented as forced-inline functions.
 */

#ifndef LED_DRIVER_INTERFACE_H
#define LED_DRIVER_INTERFACE_H

#include <asf.h>
#include "leds.h"

/**
\fn void leds_driver_init(void)
\brief Initialize the LED driver.
\details This function must:
	- Init the LED timer
	- Start the LED timer
*/

/**
\def LEDS_DRIVER_TIMER_ISR
\brief Macro to define the timer ISR for the LED timer.
\details The driver should define this to match the timer being used as the LED
	timer.  For example:
	\code
	#define LEDS_DRIVER_TIMER_ISR	ISR(TIMER0_OVF_vect)
	\endcode
*/

/**
\fn void leds_driver_set_channel(leds_channel_t channel)
\brief Turn on the given LED channel and turn off all others.
\param channel LED channel to turn on.
*/

#endif // LED_DRIVER_INTERFACE_H
