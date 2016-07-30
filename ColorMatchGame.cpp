#include <iostream>
#include "LED.hpp"
#include "Buzzer.hpp"
#include "Button.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	// Setup wiringPi
	if(wiringPiSetup() == -1) {
		cout << "wiringPiSetup() failed." << endl;
		return 1;
	}
	
	// Instantiate the components needed
	Button button(25);
	LED matchLED(3, { 0, 1, 2 });
	LED playerLED(3, { 3, 4, 5 });
	LED checkerLED(2, { 27, 28 });
	
	// Press the Button Switch to start game
	cout << "Press the button to start the game" << endl;
	while(!button.isPressed());
	
	
	
	return 0;
}