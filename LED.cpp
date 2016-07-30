#include "LED.hpp"

LED::LED(short numOfPins, std::initializer_list<short> pins, short numOfColors) :
	Sensor(numOfPins, pins),
	m_Colors(numOfColors),
	m_Active(false)
{
	// Initialize each pin
	for(short pin : pins)
		softPwmCreate(pin, 0, 100);
	
	// Allocate array of color values
	m_Values = new short[m_Colors];
	
	// Initialize array of color values
	for(short i = 0; i < numOfColors; i++)
		m_Values[i] = 255;
}

LED::~LED() {
	// Deallocate m_Values
	delete[] m_Values;
	
	// Get rid of dangling pointer
	m_Values = NULL;
}

void LED::On() {
	// Turn on all LEDs to their respective value
	for(int i = 0; i < m_Colors; i++)
		softPwmWrite(m_Pins[i], m_Values[i]);
	
	// Switch the bool
	m_Active = true;
}

void LED::Off() {
	// Turn all LEDs off
	for(int i = 0; i < m_Colors; i++)
		softPwmWrite(m_Pins[i], 0);
	
	// Switch the bool
	m_Active = false;
}

void LED::Toggle() {
	// Toggle between on and off states
	if(m_Active)
		Off();
	else
		On();
}

void LED::SetColor(std::initializer_list<short> colors) {
	int i = 0;
	
	// Set each pin to the correct value
	for(short value : colors) {
		// How to get around std::initializer_list not having subscript operator
		if(i < m_Colors)
			m_Values[i] = value;
		else
			break;
		
		i++;
	}
}