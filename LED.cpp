#include "LED.hpp"

LED::LED(short pin) :
	Sensor(1, { pin }), 
	value(255), 
	active(false)
{
	softPwmCreate(m_Pins[0], 0, 100);
}

LED::~LED() {
	DeInit();
}

void LED::On() {
	softPwmWrite(m_Pins[0], value);
	active = true;
}

void LED::Off() {
	softPwmWrite(m_Pins[0], 0);
	active = false;
}

void LED::Toggle() {
	if(active)
		Off();
	else
		On();
}

void LED::DeInit() {
	Off();
	delay(10);
}