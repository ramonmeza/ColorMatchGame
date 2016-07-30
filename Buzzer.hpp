#ifndef _BUZZER_HPP
#define _BUZZER_HPP

#include "Sensor.hpp"

class Buzzer : public Sensor {
private:

public:
	Buzzer(short pin = 0);
	~Buzzer();
	
	void Buzz(int ms = 1000);
};

#endif