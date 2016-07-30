#include <iostream>
#include "LED.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	// Setup wiringPi
	if(wiringPiSetup() == -1) {
		cout << "wiringPiSetup() failed." << endl;
		return 1;
	}
	
	LED led(2, { 0, 1 }, 2);
	
	led.SetColor({ 255, 0 });
	led.On();
	delay(500);
	led.Off();
	delay(500);
	
	led.SetColor({ 0, 255 });
	led.Toggle();
	delay(500);
	led.Toggle();
	delay(500);
	
	return 0;
}