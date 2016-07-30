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
	
	// Set up components
	LED rgb1(3, { 0, 1, 2 });
	LED rgb2(3, { 3, 4, 5 });
	LED dual(2, { 27, 28 });
	Buzzer buzzer(29);
	Button button(25);
	
	// Test components
	rgb1.Toggle();
	delay(1000);
	rgb1.Toggle();
	rgb2.Toggle();
	delay(1000);
	rgb2.Toggle();
	dual.Toggle();
	delay(1000);
	dual.Toggle();
	buzzer.Buzz(1000);
	
	while(button.isPressed() == false) {
		cout << "Press the button." << endl;
	}
	
	cout << "Everything is all cool." << endl;
	
	return 0;
}