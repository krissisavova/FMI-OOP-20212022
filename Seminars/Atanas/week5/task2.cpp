#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;

class Location {
private:
	char* name;
	unsigned size;
	unsigned capacity;
	double xCoordinates;
	double yCoordinates;

	void del() {
		delete[] name;
	}

	void copy(const Location& other) {
		setSize(other.size);
		setCapacity(other.capacity);
		setXCoordinates(other.xCoordinates);
		setYCoordinates(other.yCoordinates);

		for (unsigned i = 0; i < size; i++) {
			setName(other.name);
		}
	}

	void resize() {
		if (size >= capacity) {
			capacity *= 2;
		}
		char* newData = new char[this->capacity];
		for (unsigned i = 0; i < size; i++) {
			newData[i] = name[i];
		}
		del();
		this->name = newData;
	}

public:
	Location() {
		this->name = new char[1];
		this->name[0] = '\0';
		setSize(0);
		setCapacity(8);
		setXCoordinates(0);
		setYCoordinates(0);
		name = new char[capacity];
	}

	Location(const char* _name, unsigned _size, unsigned _capacity, double _xCoordinates, double _yCoordinates) :
		size(_size), capacity(_capacity), xCoordinates(_xCoordinates), yCoordinates(_yCoordinates) {
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}

	Location(const Location& other) {
		copy(other);
	}

	Location& operator=(const Location& other) {
		if (this != &other) {
			del();
			copy(other);
		}
		return *this;
	}
	~Location() {
		del();
	}

	const char* getName() const {
		return name;
	}

	void setName(const char* _name) {
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}

	unsigned getSize() const {
		return size;
	}

	void setSize(unsigned _size) {
		size = _size;
	}

	unsigned getCapacity() const {
		return capacity;
	}

	void setCapacity(unsigned _capacity) {
		capacity = _capacity;
	}

	double getXCoordinates() const {
		return xCoordinates;
	}

	void setXCoordinates(unsigned _xCoordinates) {
		xCoordinates = _xCoordinates;
	}

	double getYCoordinates() const {
		return yCoordinates;
	}

	void setYCoordinates(unsigned _yCoordinates) {
		yCoordinates = _yCoordinates;
	}

	friend std::ostream& operator<<(std::ostream& out, const Location& data) {
		out << "This is " << data.name << " with coordinates (" << data.xCoordinates << ", " << data.yCoordinates << ")\n";
		return out;
	}

	void print() const {
		cout << "This is " << name << " with coordinates (" << xCoordinates << ", " << yCoordinates << ")\n";
	}
};

int main() {
	Location l1("Sofia", 2, 10, 12, 24);
	cout << l1;
	cout << endl;
	l1.print();
	return 0;
}
