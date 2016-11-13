/**
 * \brief Driver definitions for the LEDs.
 */

#ifndef LEDS_DRIVER_H
#define LEDS_DRIVER_H

#include <asf.h>
#include "leds.h"

__always_inline static void leds_driver_init(void)
{
	// Initialize the timer counter to zero
	TCNT0 = 0;
	// Enable the overflow interrupt
	TIMSK0 |= _BV(TOIE0);
	// Set the clock source to internal with no prescaler.
	// Note: all other bits are cleared in this step (force OC not activated
	// and waveform generation set to mode 0).
	TCCR0B = _BV(CS00);
}

#define LEDS_DRIVER_TIMER_ISR	ISR(TIMER0_OVF_vect)

__always_inline static void leds_driver_set_channel(leds_channel_t channel)
{
	// Turn off all channels first and then we'll turn on the active one
	RED_OFF();
	GREEN_OFF();
	BLUE_OFF();

	switch (channel)
	{
		case LEDS_CHANNEL_RED:
		{
			RED_ON();
			break;
		}
		case LEDS_CHANNEL_GREEN:
		{
			GREEN_ON();
			break;
		}
		case LEDS_CHANNEL_BLUE:
		{
			BLUE_ON();
			break;
		}
		// LEDs module passed us a bad channel, drop it on the floor
		default: break;
	}
}

#endif // LEDS_DRIVER_H
