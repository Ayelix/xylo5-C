/**
 * \brief LED control module.
 * \details led_driver_interface.h describes the driver definitions required.
 */

#ifndef LEDS_H
#define LEDS_H

#include <asf.h>

/************************************************************************/
/* Typedefs                                                             */
/************************************************************************/

/**
\brief Enumeration of each LED channel available.
\details Used to identify LED channels to turn them on/off.
*/
typedef enum
{
	LEDS_CHANNEL_RED,
	LEDS_CHANNEL_GREEN,
	LEDS_CHANNEL_BLUE,
	/// Number of channels (not a real channel itself)
	LEDS_CHANNEL_MAX
} leds_channel_t;

/************************************************************************/
/* Public functions                                                     */
/************************************************************************/

/**
\brief Initialize the LEDs.
\details Must be called before any other functions in this module.
*/
void leds_init(void);

/**
\brief Update the LED brightnesses.
\details The new brightnesses will take effect the next time the LED timer
	expires.  255 is max brightness, 1 is min non-off brightness, and 0 is off.
\param brightness Array of brightnesses for each channel.
*/
void leds_update(uint8_t const brightness[LEDS_CHANNEL_MAX]);

/************************************************************************/
/* Functions to be called only by the LED driver                        */
/************************************************************************/

/// Report that the LED timer has expired
void leds_timer_expired(void);

#endif // LEDS_H
