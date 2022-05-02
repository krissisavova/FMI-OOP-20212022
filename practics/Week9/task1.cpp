#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Base {
protected:
	char* name;
	unsigned experience;

	void del() {
		delete[] name;
	}
	void copy(const Base& other) {
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		experience = other.experience;
	}
public:
	Base() {
		name = new char[1];
		name[0] = '\0';
		experience = 0;
	}
	Base(const char* _name, const unsigned& _experience) {
		setName(_name);
		setExperience(_experience);
	}
	void setName(const char* _name) {
		name = new char[strlen(_name) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
	}
	void setExperience(const unsigned& _experience) {
		experience = _experience >= 0 ? _experience : 0;
	}
	Base(const Base& other) {
		copy(other);
	}
	Base& operator=(const Base& other) {
		if (this != &other) {
			del();
			copy(other);
		}
		return *this;
	}
	~Base() {
		del();
	}

	void input() {
		cout << "Enter name: "; cin >> name;
		cout << "Enter experience: "; cin >> experience;
	}

	void print() const {
		cout << "Name: " << name << "\nExperience (in months): " << experience << endl;
	}
};

class Programmers : public Base {
private:
	bool knowsCPP;
	bool knowsCS;
	void copy(const Programmers& other) {
		Base::operator=(other);
		knowsCPP = other.knowsCPP;
		knowsCS = other.knowsCS;
	}
public:
	Programmers() : Base() {
		knowsCPP = 0;
		knowsCS = 0;
	}
	Programmers(const char* _name, const unsigned& _experience, const bool& _knowsCPP, const bool& _knowsCS)
		: Base(_name, _experience) {
		knowsCPP = _knowsCPP;
		knowsCS = _knowsCS;
	}
	Programmers(const Programmers& other) {
		copy(other);
	}
	Programmers& operator=(const Programmers& other) {
		if (this != &other) {
			copy(other);
		}
		return *this;
	}
	void input() {
		Base::input();
		cout << "Does the programmer know C++? --> "; cin >> knowsCPP;
		cout << "Does the programmer know C#? --> "; cin >> knowsCS;
	}

	void print() const {
		cout << "Programmer Information: \n";
		Base::print();
		cout << "Do they know C++? --> " << knowsCPP << "\nDo they know C#? --> " << knowsCS << endl;
	}
};

class Managers : public Base {
private:
	unsigned employees;
	void copy(const Managers& other) {
		employees = other.employees;
	}
public:
	Managers() : Base() {
		employees = 0;
	}
	Managers(const char* _name, const unsigned& _experience, const unsigned& _employees)
		: Base(_name, _experience) {
		employees = _employees;
	}
	Managers(const Managers& other) {
		copy(other);
	}
	Managers& operator=(const Managers& other) {
		if (this != &other) {
			copy(other);
		}
		return *this;
	}

	void input() {
		Base::input();
		cout << "Number of employees: "; cin >> employees;
	}

	void print() const {
		cout << "Manager Information: \n";
		Base::print();
		cout << "Number of Employees: " << employees << endl;
	}
};

int main() {
	// Test 1
	//Programmers p1("Pesho", 11, 1, 0);
	//Managers m1("Kristina", 54, 10);
	//p1.print();
	//cout << "-------------------" << endl;
	//m1.print();

	// Test 2
	Programmers p2;
	p2.input();
	p2.print();
	cout << "--------------------" << endl;
	Managers m2;
	m2.input();
	m2.print();

	return 0;
}
