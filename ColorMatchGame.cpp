#include <iostream>
#include "LED.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	
	if(wiringPiSetup() == -1) {
		cout << "wiringPiSetup() failed." << endl;
		return 1;
	}
	
	LED led(0);
	
	led.On();
	delay(1000);
	
	return 0;
}