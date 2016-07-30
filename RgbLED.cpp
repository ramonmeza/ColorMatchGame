#include "RgbLED.hpp"

RgbLED::RgbLED(short RedPin, short GreenPin, short BluePin) : 
	LED(3, { RedPin, GreenPin, BluePin }),
	m_Red(255),
	m_Green(255),
	m_Blue(255)
{}

RgbLED::~RgbLED() {
	DeInit();
}

void RgbLED::On() {
	softPwmWrite(m_Pins[0], m_Red);
	softPwmWrite(m_Pins[1], m_Green);
	softPwmWrite(m_Pins[2], m_Blue);
	
	m_Active = true;
}

void RgbLED::Off() {
	softPwmWrite(m_Pins[0], 0);
	softPwmWrite(m_Pins[1], 0);
	softPwmWrite(m_Pins[2], 0);
	
	m_Active = false;
}
