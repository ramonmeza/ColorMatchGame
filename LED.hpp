#ifndef _LED_HPP
#define _LED_HPP

#include "Sensor.hpp"
#include <softPwm.h>

class LED : public Sensor {
private:
	short	m_Colors;
	short* 	m_Values;
	bool 	m_Active;

public:
	LED(short numOfPins = 1, std::initializer_list<short> pins = { 0 });
	~LED();
	
	void On();
	void Off();
	void Toggle();
	
	void SetColor(std::initializer_list<short> colors);
	short* GetColor() { return m_Values; }
};

#endif