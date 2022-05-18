#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Shape {
public:
	virtual void enterData() = 0;
	virtual void showArea() = 0;
};

class Rectangle : public Shape {
private:
	double width;
	double height;
public:
	Rectangle() : width(0), height(0) {}
	Rectangle(double _width, double _height) : width(_width), height(_height) {}

	void enterData() override {
		cout << "Enter width: ";  cin >> width;
		cout << "Enter height: ";  cin >> height;
	}
	void showArea() override {
		cout << "Area: " << width * height << endl;
	}
};

class Circle : public Shape {
private:
	double radius;
	const char name[7] = "Circle";
public:
	Circle() : radius(0) {}
	Circle(double _radius) : radius(_radius) {}

	void enterData() override {
		cout << "Enter radius: ";  cin >> radius;
	}

	void showArea() override {
		cout << "Area: " << 3.14 * radius * radius << endl;
	}
};

int main() {
	Shape* rect = new Rectangle(10, 30);
	Shape* circle = new Circle(25);

	rect->showArea();
	circle->showArea();

	cout << "-----------------------\n";

	Rectangle rect1;
	Circle circle1;
	//rect1.showArea();

	rect1.enterData();
	rect1.showArea();

	circle1.enterData();
	circle1.showArea();

	return 0;
}
