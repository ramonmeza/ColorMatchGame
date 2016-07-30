#ifndef _LED_HPP
#define _LED_HPP

#include "Sensor.hpp"
#include <softPwm.h>

class LED : public Sensor {
private:
	short value;

protected:
	bool active;

public:
	LED(short pin = 0);
	~LED();

	virtual void On();
	virtual void Off();
	void Toggle();
	
	void DeInit();
};

#endif