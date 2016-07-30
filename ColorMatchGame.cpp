#include <iostream>
#include "Button.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	// Setup wiringPi
	if(wiringPiSetup() == -1) {
		cout << "wiringPiSetup() failed." << endl;
		return 1;
	}
	
	Button btn(0);
	int i = 0;
	
	while(1) {
		if(btn.isPressed()) {
			cout << i << endl;
			i++;
		}
	}
	
	return 0;
}