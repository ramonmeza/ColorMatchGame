#include "Sensor.hpp"

Sensor::Sensor(short numOfPins, std::initializer_list<short> pins) :
	numOfPins(numOfPins)
{
	m_Pins = new short[numOfPins];
	
	short i = 0;
	for(short x: pins) {
		m_Pins[i] = x;
		i++;
	}
}

Sensor::~Sensor() {
	delete[] m_Pins;
	m_Pins = NULL;
}

std::ostream& operator<<(std::ostream& os, const Sensor& obj) {

	for(short i = 0; i < obj.numOfPins; i++)
		os << obj.m_Pins[i] << std::endl;
	
	return os;
}