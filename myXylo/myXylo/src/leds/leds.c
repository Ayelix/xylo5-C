/**
* \brief LED control module.
* \details led_driver_interface.h describes the driver definitions required.
 */

#include <asf.h>
#include <string.h>

#include "leds.h"
#include "leds_driver_interface.h"
#include "leds_driver.h"

/************************************************************************/
/* Private variables                                                    */
/************************************************************************/

/// LEDs module data
static struct
{
	/// Current brightness for each color channel
	uint8_t brightness[LEDS_CHANNEL_MAX];
	/// Next channel to drive (index into brightness array)
	leds_channel_t nextChannel;
} leds;

/************************************************************************/
/* Public functions                                                     */
/************************************************************************/

void leds_init(void)
{
	// Clear out the data
	memset(&leds, 0, sizeof(leds));

	// Now that everything is ready, initialize the driver to kick off the LED
	// timer.
	leds_driver_init();

	// HACK force full brightness for all channels
	LEDS_ENABLE();
}

void leds_update(uint8_t const brightness[LEDS_CHANNEL_MAX])
{
	// Copy the data so it will be updated on the next timer tick
	memcpy(&leds, brightness, sizeof(leds));
	// The active channel is not changed here, so an update may take effect in
	// the middle of the channel scanning (i.e. not on the next reset to the
	// first channel).
}

LEDS_DRIVER_TIMER_ISR
{
	// Activate the next channel.  The next channel tracker is always one
	// channel ahead of what is actually being driven.
	leds_driver_set_channel(leds.nextChannel);

	// Move on to the next channel
	leds.nextChannel++;
	if (leds.nextChannel >= LEDS_CHANNEL_MAX)
	{
		leds.nextChannel = 0;
	}
}