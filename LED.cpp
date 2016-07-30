#include "LED.hpp"

LED::LED(short pin) :
	Sensor(1, { pin }), 
	m_Value(255), 
	m_Active(false)
{
	softPwmCreate(m_Pins[0], 0, 100);
}

LED::LED(int numOfPins, std::initializer_list<short> pins) :
	Sensor(numOfPins, pins),
	m_Active(false)
{
	for(int i = 0; i < numOfPins; i++)
		softPwmCreate(m_Pins[i], 0, 100);
}

LED::~LED() {
	DeInit();
}

void LED::On() {
	softPwmWrite(m_Pins[0], m_Value);
	m_Active = true;
}

void LED::Off() {
	softPwmWrite(m_Pins[0], 0);
	m_Active = false;
}

void LED::Toggle() {
	if(m_Active)
		Off();
	else
		On();
}

void LED::DeInit() {
	Off();
	delay(10);
}