#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Worker {
protected:
	std::string name;
	std::string ucn;
public:
	Worker(std::string _name, std::string _ucn) {
		name = _name;
		ucn = (_ucn.size() == 10) ? _ucn : "2201011111";
	}
	//virtual void exactOccupation() = 0;
	virtual void exactOccupation() {
		cout << "The worker's name is" << name << " and they have UCN: " << ucn << endl;
	}
};

class Gardener : public Worker {
public:
	Gardener(std::string _name, std::string _ucn) : Worker(_name, _ucn) {}
	void exactOccupation() override {
		cout << "The worker " << name << " with UCN: " << ucn << " is a gardener.\n";
	}
};

class Chef : public Worker {
public:
	Chef(std::string _name, std::string _ucn) : Worker(_name, _ucn) {}
	void exactOccupation() override {
		cout << "The worker " << name << " with UCN: " << ucn << " is a chef.\n";
	}
};

int main() {
	Gardener g("Gosho", "9503142323");
	Chef c("Pesho", "9908163232");
	g.exactOccupation();
	c.exactOccupation();
	return 0;
}
