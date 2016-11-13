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

static void delay100ms(void)
{
	for (uint16_t i = 0; i < 400; i++)
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

	// HACK the LEDs module forces full brightness
	// We have to force the LEDs off and kill interrupts to stop it after a
	// while so the LEDs aren't on forever.  Just a blink on startup.
	delay100ms();
	cli();
	LEDS_DISABLE();

	// Everything runs on interrupts so we'll just sit here.
	// TODO can we go into sleep mode or something?
	while (true);
}
