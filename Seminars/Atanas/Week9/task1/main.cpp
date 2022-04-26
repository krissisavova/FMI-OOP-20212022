#include <iostream>
#include "Temperature.h"
#include "Forecast.h"
using std::cout;
using std::cin;
using std::endl;

int main() {
	Temperature t1, t2(-20, -21, -2);
	cout << t1;
	cout << t2;
	bool comparingTemperatures = t2 == t1;
	cout << comparingTemperatures << endl; // should return 1, for t2 contains an invalid value

	Temperature t3;
	t3.inputTemperatures();
	cout << t3;

	Forecast f1;
	cin >> f1;
	cout << f1;
	return 0;
}
