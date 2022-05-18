#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Vehicle {
protected:
	double speed;
	double price;
	double weight;
public:
	Vehicle(double _speed, double _price, double _weight) : speed(_speed), price(_price), weight(_weight) {}
	double getSpeed() const {
		return speed;
	}
	double getPrice() const {
		return price;
	}
	double getWeight() const {
		return weight;
	}
	virtual void print() = 0;
};

class Plane : public Vehicle {
private:
	double maxHeight;
public:
	Plane(double _speed, double _price, double _weight, double _maxHeight) : maxHeight(_maxHeight), Vehicle(_speed, _price, _weight) {}
	double getMaxHeight() const {
		return maxHeight;
	}
	void print() override {
		cout << "This plane has a speed of " << speed << ", it costs " << price << " and its weight is " << weight << endl;
		cout << "Its maximal height is " << maxHeight << endl;
	}
};

enum Type {
	TRUCK = 0,
	LUXURIOUS,
	ORDINARY
};

class Car : public Vehicle {
private:
	Type type;
public:
	Car(double _speed, double _price, double _weight, Type _type) : type(_type), Vehicle(_speed, _price, _weight) {}
	Type getType() const {
		return type;
	}
	void setType(Type& _type) {
		if (_type >= TRUCK && _type <= ORDINARY) {
			type = _type;
		}
	}
	void print() override {
		cout << "This car has a speed of " << speed << ", it costs " << price << " and its weight is " << weight << endl;
		cout << "Its type is ";
		switch (type) {
		case TRUCK: cout << "TRUCK.\n"; break;
		case LUXURIOUS: cout << "LUXURIOUS.\n"; break;
		case ORDINARY: cout << "ORDINARY.\n"; break;
		default: cout << "UNKNOWN.\n"; break;
		}
	}
};

class Ship : public Vehicle {
private:
	double displacementTonage; // long ton
public:
	Ship(double _speed, double _price, double _weight, double _displacementTonage) : displacementTonage(_displacementTonage), Vehicle(_speed, _price, _weight) {};
	double getDisplacementTonage() const {
		return displacementTonage;
	}
	void print() override {
		cout << "This ship has a speed of " << speed << ", it costs " << price << " and its weight is " << weight << endl;
		cout << "Its displacement tonage is equal to " << displacementTonage << " long tons." << endl;
	}
};

//void printVehiclesWIthHighSpeed(Vehicle* arr, unsigned size) {
//	for (unsigned i = 0; i < size; i++) {
//		if (arr[i].getSpeed() > 200) {
//
//		}
//	}
//}

int main() {
	Plane p(930, 100000, 80000, 11582.4);
	Car c(140, 50000, 1760, TRUCK);
	Ship s(900, 90000, 78000, 22);

	p.print();
	cout << "------------------\n";
	c.print();
	cout << "------------------\n";
	s.print();
	return 0;
}
