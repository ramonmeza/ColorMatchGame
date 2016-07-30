#include "Button.hpp"

Button::Button(short pin) :
	Sensor(1, { pin })
{
	// Set pin to get input
	pinMode(pin, INPUT);
}