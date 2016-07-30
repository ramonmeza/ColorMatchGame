#ifndef _LED_HPP
#define _LED_HPP

#include "Sensor.hpp"
#include <softPwm.h>

class LED : public Sensor {
private:
	short m_Value;

protected:
	bool m_Active;

public:
	LED(short pin = 0);
	LED(int numOfPins, std::initializer_list<short> pins);
	~LED();

	virtual void On();
	virtual void Off();
	void Toggle();
	
	void DeInit();
};

#endif