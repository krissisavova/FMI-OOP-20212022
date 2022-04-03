#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Triangle {
private:
	unsigned a;
	unsigned b;
	unsigned c;

public:
	Triangle() {
		setA(0);
		setB(0);
		setC(0);
	}
	Triangle(unsigned _a, unsigned _b, unsigned _c) : a(_a), b(_b), c(_c) {}

	unsigned getA() const {
		return a;
	}

	void setA(unsigned _a) {
		this->a = _a;
	}

	unsigned getB() const {
		return b;
	}

	void setB(unsigned _b) {
		this->b = _b;
	}

	unsigned getC() const {
		return c;
	}

	void setC(unsigned _c) {
		this->c = _c;
	}

	void changeA(unsigned newA) {
		if (newA + b > c && newA + c > b && b + c > newA) {
			this->a = newA;
		}
		else {
			cout << "Invalid value for side A" << endl;
			return;
		}
	}

	void changeB(unsigned newB) {
		if (newB + a > c && newB + c > a && a + c > newB) {
			this->b = newB;
		}
		else {
			cout << "Invalid value for side B" << endl;
			return;
		}
	}

	void changeC(unsigned newC) {
		if (newC + b > a && newC + a > b && a + b > newC) {
			this->c = newC;
		}
		else {
			cout << "Invalid value for side C" << endl;
			return;
		}
	}

	unsigned findPerimeter() {
		return a + b + c;
	}

	void print() const {
		cout << "Triangle with sides: " << a << ", " << b << ", " << c << endl;
	}

	void typeOfTriangle() {
		if (a == b && b == c) {
			cout << "Equilateral" << endl;
		}
		else if (a == b || b == c || a == c) {
			cout << "Isosceles" << endl;
		}
		else {
			cout << "Scalene" << endl;
		}
	}
};

int main() {
	Triangle t1;
	t1.print();
	cout << "-----------\n";
	Triangle t2(2, 3, 4);
	t2.print();
	cout << "Perimeter: " << t2.findPerimeter() << endl;
	t2.changeA(5);
	t2.print();
	cout << "Perimeter: " << t2.findPerimeter() << endl;
	t2.changeB(34);
	t2.print();
	cout << "-----------\n";
	Triangle t3(5, 5, 6);
	t3.print();
	t3.typeOfTriangle();
	t3.changeC(5);
	t3.print();
	t3.typeOfTriangle();
	t3.changeB(4);
	t3.changeA(0);
	t3.print();
	t3.typeOfTriangle();
	return 0;
}
