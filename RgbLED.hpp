#ifndef _RGBLED_HPP
#define _RGBLED_HPP

#include "LED.hpp"

class RgbLED : public LED {
private:
	short m_Red;
	short m_Green;
	short m_Blue;
	
public:
	RgbLED(short RedPin = 0, short GreenPin = 1, short BluePin = 2);
	~RgbLED();
	
	void SetColor(short Red = 0, short Green = 0, short Blue = 0) {
		m_Red = Red;
		m_Green = Green;
		m_Blue = Blue;
	}
	
	void On();
	void Off();
};

#endif