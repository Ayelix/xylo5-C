# xylo5-c Startup Behavior #

This directory contains analysis of the activity on the xylo5-c when power is
applied.  The most obvious behavior is that all LEDs flash briefly when the
battery is inserted.  The activity of the LEDs, test points, and SPI bus are
analyzed here.

No activity was found on the SKT5 pins (which are connected to the ATMega UART
pins).

Analysis was performed with a [PCSGU250](http://www.vellemanusa.com/products/view/?id=524708)
2-channel oscilloscope.  The channel count, sample rate, trigger settings, etc.
are quite limited, so most multi-signal comparisons require multiple scope
captures to be compared. <br />
The xylo5-c was powered using a [Bus Pirate](http://dangerousprototypes.com/docs/Bus_Pirate)
as an easily-togglable power supply.  The LEDs probably overdraw the 150mA
current capacity, which may be cause of the visible supply voltage dips in the
scope captures.

TODO: check the correlation of the LED and SPI activity.  My scope isn't good
enough to capture the SPI traffic along with LED activity.

## SPI ##

The SPI traffic is analyzed in this forum thread (also see the separate thread
linked from this one): <br />
[http://xylobandhacking.freeforums.net/thread/19/spi-traffic-on-startup](http://xylobandhacking.freeforums.net/thread/19/spi-traffic-on-startup)

The captured radio configuration data is also included in the [SPI/](./SPI/)
directory in case the forum goes down.

## LEDs / Test Points ##

After power is applied, all LEDs (and all 3 colors of each) turn on briefly.
The LEDs turn on approx. 165ms after power is applied and stay on for 110ms.
TP1 goes high approx. 105ms after power is applied and stays high until the
LEDs turn on (approx. 60ms).

More details appear in the following sections.

### LED Control Details ###

The LED control circuit appears to consist of 4 MOSFETs, one per color channel
to switch the color's cathode line and one to switch the output of the three
others on/off.

The color channels (red, green, blue) seem to be divided into time-slots so that
only one channel is driven at a time.  This is based on the assumption that the
initial LED flash is at full brightness.  If the LEDs can go to higher
brightness than the initial flash, then this analysis will be incorrect.

#### Color Channel Cathode Control ####

On the initial power-up flash, each color channel is driven one at a time for
250us.  The pattern repeats every 750us (1.333kHz), with the time-slots in the
order: red, green, blue.  It seems likely that each channel could be driven for
only part of its 250us time-slot to adjust the brightness of that channel.
Effectively like 1.333kHz PWM control but with the maximum duty cycle limited to
33% for each channel. <br />
**Conclusion: the cathode control signals are divided into 250us time-slots with
the pulse duration during each time-slot _possibly_ controlling the
corresponding color channel brightness.** <br />
Relevant scope captures: [TP4+TP5][TP4+TP5], [TP4+TP6][TP4+TP6]

The pulses on the cathode control signals (the control pins from the ATMega, not
the test points) begin approx. 104ms after power-up.  This is the same time that
TP1 goes high and is _before_ the TP7 overall cathode control goes high to start
the initial LED flash.  Additionally, the pulses continue indefinitely after the
TP7 control goes low to end the initial LED flash. <br />
**Conclusion: the cathode control signals are pulsed constantly and the TP7
control signal is used for overall on/off control.** <br />
Relevant scope captures: [TP4+PB7][TP4+PB7], [TP5+PB6][TP5+PB6], [TP6+PC3][TP6+PC3]


<!-- Link definitions -->
[TP4+TP5]: ./LED/TP_multi/TP4+TP5_0.1ms_1.png
[TP4+TP6]: ./LED/TP_multi/TP4+TP6_0.1ms_1.png
[TP4+PB7]: ./LED/GPIO/TP4+PB7_20ms.png
[TP5+PB6]: ./LED/GPIO/TP5+PB6_20ms.png
[TP6+PC3]: ./LED/GPIO/TP6+PC3_50ms.png