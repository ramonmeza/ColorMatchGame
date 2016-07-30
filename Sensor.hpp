#ifndef _SENSOR_HPP
#define _SENSOR_HPP

#include <iostream>
#include <initializer_list>
#include <wiringPi.h>

class Sensor {
private:
	short numOfPins;
	
protected:
	short* m_Pins;
	
public:
	Sensor(short numOfPins = 1, std::initializer_list<short> pins = { 0 });
	~Sensor();
};

#endif