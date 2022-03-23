#include <iostream>
using std::cin;
using std::cout;
using std::endl;

enum RGB {
	None,
	Red,
	Green,
	Blue
};

struct Colour {
	RGB colour[3]; // 0 - values for red, 1 - values for green, 2 - values for blue
	char nameOfNewColour[40];
};

//[None, None, None] 0, 0, 0 = 0 -> Black
//[None, None, Red] 0, 0, 1 = 1 -> Blue
//[None, None, Green] 0, 0, 2 = 2 -> Green
//[None, None, Blue] 0, 0, 3 = 3 -> Red
//[Red, Green, None] 1, 2, 0 = 3 -> Yellow
//[Red, Blue, None] 1, 3, 0 = 4 -> Purple
//[Green, Blue, None] 2, 3, 0 = 5 -> Lightblue (Cyan)
//[Red, Green, Blue] 1, 2, 3 = 6 -> White

bool checkColourArray(const Colour& c) {
	if (c.colour[0] != RGB::None && c.colour[0] != RGB::Red) {
		return false;
	}
	if (c.colour[1] != RGB::None && c.colour[1] != RGB::Green) {
		return false;
	}
	if (c.colour[2] != RGB::None && c.colour[2] != RGB::Blue) {
		return false;
	}
	return true;
}

void mixColours(Colour& c) {
	if (checkColourArray(c)) {
		std::cout << "Not correct values array" << std::endl;
		return;
	}
	unsigned values = 0;
	for (unsigned i = 0; i < 3; ++i) {
		values += c.colour[i]; // ще се натрупват стойности	и така всяка крайна стойност ще представя крайния цвят
	}

	switch (values) { // 0 - value for black, 1 - value for red, 2 - value for green, 3 - value for blue/yellow, 4 - value for purple, 5 - value for cyan, 6 - value for white
	case 0: strcpy_s(c.nameOfNewColour, "black"); break;
	case 1: strcpy_s(c.nameOfNewColour, "red"); break;
	case 2: strcpy_s(c.nameOfNewColour, "green"); break;
	case 3: 
		if (c.colour[0] == RGB::None && c.colour[1] == RGB::None){
			strcpy_s(c.nameOfNewColour, "blue"); 
		}
		else {
			strcpy_s(c.nameOfNewColour, "yellow"); 
		}
		break;
	case 4: strcpy_s(c.nameOfNewColour, "purple"); break;
	case 5: strcpy_s(c.nameOfNewColour, "cyan"); break;
	case 6: strcpy_s(c.nameOfNewColour, "white"); break;
	default: strcpy_s(c.nameOfNewColour, "UNKNOWN"); break;
	}
}

int main() {
	Colour setColour1 = { {Red, Blue, Green} };
	Colour setColour2 = { {None, Blue, Green} };
	Colour setColour3 = { {Red, None, Green} };
	Colour setColour4 = { {None, None, Green} };
	mixColours(setColour1);
	mixColours(setColour2);
	mixColours(setColour3);
	mixColours(setColour4);
	cout << setColour1.nameOfNewColour << endl;
	cout << setColour2.nameOfNewColour << endl;
	cout << setColour3.nameOfNewColour << endl;
	cout << setColour4.nameOfNewColour << endl;
	return 0;
}
