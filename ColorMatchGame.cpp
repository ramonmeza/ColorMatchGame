#include <iostream>
#include "Buzzer.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	// Setup wiringPi
	if(wiringPiSetup() == -1) {
		cout << "wiringPiSetup() failed." << endl;
		return 1;
	}
	
	Buzzer buzz(0);
	
	buzz.Buzz(1000);
	
	return 0;
}