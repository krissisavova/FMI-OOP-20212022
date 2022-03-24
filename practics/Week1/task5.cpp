#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Car {
	char brand[40];
	char model[40];
	char colour[20];
	double price;
};

struct Person {
	char name[50];
	double salary;
};

void printCarForPerson(Person person[], unsigned numOfPeople, Car cars[], unsigned numOfCars) {

	bool cannotBuyAnyCar = true;

	for (unsigned i = 0; i < numOfPeople; i++) {
		cout << person[i].name << " can afford the following cars: \n";

		for (unsigned j = 0; j < numOfCars; j++) {
			if (cars[j].price <= person[i].salary * 0.3) {
				cout << cars[j].model << " " << cars[j].brand << " " << cars[j].colour << " for $" << cars[j].price << endl;
				cannotBuyAnyCar = false;
			}
		}
		if (cannotBuyAnyCar) {
			cout << "---\n";
		}
		cout << endl;
		cannotBuyAnyCar = true;
	}
}

int main() {
	Person p[3] = { {"Kristina", 250000}, {"John", 160000}, {"Liz", 200000} };
	Car c[3] = { {"Renault", "Clio", "red", 80000}, {"Opel", "Insignia", "brown", 60000}, {"Skoda", "Octavia", "black", 50000} };

	printCarForPerson(p, 3, c, 3);

	return 0;
}
