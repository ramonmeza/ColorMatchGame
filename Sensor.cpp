#include "Sensor.hpp"

Sensor::Sensor(short numOfPins, std::initializer_list<short> pins) :
	numOfPins(numOfPins)
{
	// Allocate memory on heap for m_pins
	m_Pins = new short[numOfPins];
	
	// Initialize array of pins
	short i = 0;
	for(short x: pins) {
		// Set each pin to the correct value
		m_Pins[i] = x;
		i++;
	}
}

Sensor::~Sensor() {
	// Deallocate m_Pins
	delete[] m_Pins;
	
	// Get rid of dangling pointer
	m_Pins = NULL;
}