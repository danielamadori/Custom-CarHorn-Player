#include "Display.hpp"

Display display;

void Display::write(unsigned short digit) {
	Serial.print("Display write: ");
	Serial.println(digit);

	if(digit > DIGITS_NUMBER)
		turnOff();
	else
		for (unsigned short i = 0; i < SEGMENT_NUMBER; ++i)
			digitalWrite(pins[i], digits[digit][i]);
}

void Display::loading(unsigned short repetNumber){
        if (repetNumber == 0)
                return;
        --repetNumber;
        loading(repetNumber);

	//TODO
	//Serpentina iniziale
	/*int snake[] = {a, b, g, e, d, c, g, f};

	for(unsigned short i = 0; i < sizeof(snake) / sizeof(snake[0]); i++) {
		digitalWrite(snake[i], HIGH);
		delay(100);
		digitalWrite(snake[i], LOW);
	}
	*/	
}

void Display::setup(void){
	for(unsigned short i = 0; i < SEGMENT_NUMBER; i++)
		pinMode(pins[i], OUTPUT);
}


void Display::turnOff(void){
	for (unsigned short segCount = 0; segCount < SEGMENT_NUMBER; ++segCount)
		digitalWrite(pins[segCount], 1);
}
