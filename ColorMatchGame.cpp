#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

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
	
	// Seed random
	srand(static_cast<unsigned int>(time(NULL)));
	
	// Instantiate the components needed
	Button button(25);
	LED matchLED(3, { 0, 1, 2 });
	LED playerLED(3, { 3, 4, 5 });
	LED checkerLED(2, { 27, 28 });
	Buzzer buzzer(29);
	
	// Tell player what's going on
	cout << "Press the button when the two LED's colors match." << endl;
	cout << "The faster you make a match, the more points you get!" << endl;
	cout << "Be careful, though. If you make a mistake it'll cost" << endl;
	cout << "you a life, and you only have three to spare." << endl << endl;
	
	// Press the Button Switch to start game
	cout << "Press the button to start the game" << endl << endl;
	while(!button.isPressed());

	/*
	// This counts by seconds 
	time_t prev = time(NULL);
	while(1) {
		time_t cur = time(NULL);
		if(cur - prev > 0) {
			cout << cur << endl;
			prev = cur;
		}
	}
	*/
	
	// Game variables
	short threshold = 50;
	
	short lives = 3;
	unsigned int score = 0;
	short round = 1;
	
	// Game loop
	while(1) {
		// Round variables
		unsigned int roundPoints = 0;
		bool roundWon = false;
		
		short correctRed = 0;
		short correctGreen = 0;
		short correctBlue = 0;
		
		short elapsed;
		time_t startTime, curTime;
		
		// Get random color for matchLED (3 seconds)
		elapsed = 0;
		startTime = time(NULL);
		while(elapsed < 3) {
			elapsed = time(NULL) - startTime;
			
			correctRed = (rand() * 2) % 255;
			correctGreen = (rand() * 3) % 255;
			correctBlue = (rand() * 5) % 255;
			
			matchLED.SetColor({ correctRed, correctGreen, correctBlue });
			matchLED.On();
		}
		
		// Round loop (10 seconds)
		elapsed = 0;
		startTime = time(NULL);
		time_t prevTime = time(NULL);
		while(elapsed < 30) {
			elapsed = time(NULL) - startTime;
			
			// Update color once a second
			curTime = time(NULL);
			if((curTime - prevTime) > 0) {
				prevTime = curTime;
				
				short red = (rand() * 2) % 255;
				short green = (rand() * 3) % 255;
				short blue = (rand() * 5) % 255;
				playerLED.SetColor({ red, green, blue });
				playerLED.On();
			}
			
			// If button is pressed and it's a close enough color
			if(button.isPressed() && 
				(playerLED.GetColor()[0] - correctRed) < threshold && 
				(playerLED.GetColor()[1] - correctGreen) < threshold && 
				(playerLED.GetColor()[2] - correctBlue) < threshold)
			{
				// You won!
				roundWon = true;
				break;
			} else if(button.isPressed()) {
				// If you pressed on the wrong color
				roundWon = false;
				break;
			}
		}
		
		// End of round info
		if(roundWon) {
			cout << "Nice job! You won the round." << endl;
			
			// Calcuate scores
			if(elapsed >= 30)
				roundPoints = 5;
			else if(elapsed >= 25)
				roundPoints = 10;
			else if(elapsed >= 2)
				roundPoints = 15;
			else if(elapsed >= 15)
				roundPoints = 20;
			else if(elapsed >= 10)
				roundPoints = 25;
			else if(elapsed >= 5)
				roundPoints = 30;
			else
				roundPoints = 50;
			
			cout << "You got " << roundPoints << " points!" << endl;
			
			// Add points to total score
			score += roundPoints;
		} else {
			cout << "So close. You lost the round and a life." << endl;
			cout << "Lives remaining: " << --lives << endl;
		}
		
		// Turn LEDs off
		matchLED.Off();
		playerLED.Off();
		
		// Round LED
		if(roundWon) {
			// Set checkerLED to Green
			checkerLED.SetColor({ 0, 255 });
			checkerLED.On();
			
			// Good buzz
			buzzer.Buzz(250);
			delay(250);
			buzzer.Buzz(250);
			delay(250);
			
			// Increment the round counter
			round++;
		} else { 
			// Set checkerLED to Red
			checkerLED.SetColor({ 255, 0 });
			checkerLED.On();
		
			// Bad buzz
			buzzer.Buzz(1000);
		}
		
		checkerLED.Off();
		
		// If you have enough lives to continue
		if(lives <= 0) {
			// Press the Button Switch to start game
			cout << "Game over." << endl << endl;
			break;
		}
		
		// Display score
		cout << "Your current score is: " << score << endl;
		
		// Press button to continue
		delay(1000);
		cout << "Press button to start next round..." << endl;
		while(!button.isPressed());
	}
	
	// End of game
	cout << "You completed " << round << " rounds!" << endl;
	cout << "Your final score: " << score << endl << endl;
	
	return 0;
}