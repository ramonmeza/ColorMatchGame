#include "Buzzer.hpp"

Buzzer::Buzzer(short pin) :
	Sensor(1, { pin })
{
	// Set pin to output
	pinMode(m_Pins[0], OUTPUT);	
}

Buzzer::~Buzzer() {
	digitalWrite(m_Pins[0], LOW);
	delay(10);
}

void Buzzer::Buzz(int ms) {
	// Buzz for ms milliseconds
	digitalWrite(m_Pins[0], HIGH);
	delay(ms);
	
	// Turn off
	digitalWrite(m_Pins[0], LOW);
	delay(10);
}