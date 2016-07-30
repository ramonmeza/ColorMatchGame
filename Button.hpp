#ifndef _BUTTON_HPP
#define _BUTTON_HPP

#include "Sensor.hpp"

class Button : public Sensor {
private:
	bool GetState() { return !(digitalRead(m_Pins[0])); }
	
public:
	Button(short pin = 0);
	
	// Return whether the button is pressed or not
	bool isPressed() { return GetState(); }
};

#endif