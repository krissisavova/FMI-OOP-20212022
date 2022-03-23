#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Planet {
	char name[20];
	long double distanceFromSun;
	long double diameter;
	long double mass;
};

void readPlanet(Planet& planet) {
	cout << "Enter name of planet: ";
	cin.getline(planet.name, 19);
	cout << "Enter distance from Sun: "; cin >> planet.distanceFromSun;
	cout << "Enter diameter: "; cin >> planet.diameter; 
	cout << "Enter mass: "; cin >> planet.mass;
}

void printPlanet(Planet planet) {
	cout << "Planet Data: " << planet.name << "\t" << planet.distanceFromSun << "\t" << planet.diameter << "\t" << planet.mass << endl;
}

long double distanceFromSunInSeconds(Planet& planet) {
	// s = v * t, s = distanceFromSun, v = 299792
	long double timeInSeconds;
	timeInSeconds = planet.distanceFromSun / 299792;

	return timeInSeconds;
}

void readPlanets(Planet planet[], unsigned size) {
	for (size_t i = 0; i < size; i++) {
		cin.ignore();
		readPlanet(planet[i]);
	}
	cout << endl;
}

void printPlanets(Planet* planet, unsigned size) {
	for (size_t i = 0; i < size; i++) {
		printPlanet(planet[i]);
	}
	cout << endl;
}

int main() {
	Planet p;
	readPlanet(p);
	printPlanet(p);
	cout << "Time needed for the light to reach from the Sun to the planet /in seconds/: " << distanceFromSunInSeconds(p) << endl;
	cout << "---------------------------------------------------" << endl;
	
	Planet planet[5];
	readPlanets(planet, 5);
	printPlanets(planet, 5);
	return 0;
}
