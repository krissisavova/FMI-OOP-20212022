#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Device {
protected:
	unsigned memory;
	double speed;
	unsigned cores;
public:
	Device(const unsigned& _memory, const double& _speed, const unsigned& _cores) {
		setMemory(_memory);
		setSpeed(_speed);
		setCores(_cores);
	}
	void setMemory(const unsigned& _memory) {
		memory = _memory;
	}
	void setSpeed(const double& _speed) {
		speed = _speed >= 0 ? _speed : 0;
	}
	void setCores(const unsigned& _cores) {
		cores = _cores;
	}
	void print() const {
		cout << "Memory: " << memory << "\nSpeed: " << speed << "\nNumber of cores: " << cores << endl;
	}
};

class Laptop : public Device {
private:
	double screenResolution;
public:
	Laptop(const unsigned& _memory, const double& _speed,
		const unsigned& _cores, const double& _screenResolution) : Device(_memory, _speed, _cores) {
		screenResolution = _screenResolution >= 1 ? _screenResolution : 1;
	}
	void print() const {
		cout << "Laptop Information: \n";
		Device::print();
		cout << "Screen resolution: " << screenResolution << endl;
	}
};

class Cellphone : public Device {
private:
	double screenSize;
public:
	Cellphone(const unsigned& _memory, const double& _speed,
		const unsigned& _cores, const double& _screenSize) : Device(_memory, _speed, _cores) {
		screenSize = _screenSize >= 1 ? _screenSize : 1;
	}
	void print() const {
		cout << "Cellphone Information: \n";
		Device::print();
		cout << "Screen size: " << screenSize << endl;
	}
};

int main() {
	Device d1(32, 12.5, 2);
	Laptop l1(32, -23, 2, 20);
	Cellphone c1(64, 132.2, 1, 15.5);
	d1.print();
	cout << "----------------" << endl;
	l1.print();
	cout << "----------------" << endl;
	c1.print();
	return 0;
}
