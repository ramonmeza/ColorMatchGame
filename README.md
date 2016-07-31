# Color Match Game
##### For Raspberry Pi 3 &
##### [SunFounder Sensor Kit v1.0](https://www.sunfounder.com/learn/category/Sensor-Kit-v1-0-for-Raspberry-Pi.html)
###### By Ramon Meza

---

## Overview
A simple game for Raspberry Pi 3 using the sensors from SunFounder Sensor Kit v1.0 for Raspberry Pi.

The objective of the game is to match the color of two LEDs by pressing the button when the same color appears in a second LED that matched the first LED. The faster you match a color, the more points you get.

## Getting Set Up
To make the project yourself, you will need to having a Raspberry Pi 3 and the sensors listed in below (I got them from the SunFounder Sensor Kit v1.0 for Raspberry Pi, but they should work with anything):
- 2x RGB LEDs
- 1x Dual-Color Common-Cathode LED (Red/Yellow or Red/Green work best)
- 1x Active Buzzer
- 1x Button Switch

#### Wiring
Here's a description of how to wire each component (the GPIO numbers are based off of wiringPi's GPIO numbers. [You can find out about this here](http://wiringpi.com/pins/)).

- RGB LED (`matchLED` in ColorMatchGame.cpp)
    - Red Pin -> GPIO 0
    - Green Pin -> GPIO 1
    - Blue Pin -> GPIO 2
- RGB LED (`playerLED` in ColorMatchGame.cpp)
    - Red Pin -> GPIO 3
    - Green Pin -> GPIO 4
    - Blue Pin -> GPIO 5
- Dual-Color Common-Cathode LED (`checkerLED` in ColorMatchGame.cpp)
    - Red Pin -> GPIO 27
    - Other Pin -> GPIO 28
- Active Buzzer (`buzzer` in ColorMatchGame.cpp)
    - Signal Pin -> GPIO 29
- Button Switch (`button` in ColorMatchGame.cpp)
    - Signal -> GPIO 25

**NOTE** - These are changable inside of ColorMatchGame.cpp. To reassign them, follow this template (*line 22* in ColorMatchGame.cpp):
```c++
// Instantiate the components needed
Button button(SignalPinNumber);
LED matchLED(3, { RedPinNumber, GreenPinNumber, BluePinNumber });
LED playerLED(3, { RedPinNumber, GreenPinNumber, BluePinNumber });
LED checkerLED(2, { RedPinNumber, OtherPinNumber });
Buzzer buzzer(SignalPinNumber);
```

#### Running the Program
You will also **NEED** to have [wiringPi](http://wiringpi.com/) set up on your Raspberry Pi 3.

Download or clone this project and place it into a directory on your Raspberry Pi 3. Once done you can run the following commands (assuming you are inside the ColorMatchGame directory):
- `make test`
    - This will test to make sure your sensors are working
- `make` then `sudo ./ColorMatchGame`
    - This will make and then run the game