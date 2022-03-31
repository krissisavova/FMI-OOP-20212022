#include "Person.h"
#include <iostream>
#include <cstring>

void Person::del() {
	delete[] name;
}

void Person::copy(const Person& other) {
	setAge(other.age);
	setName(other.name);
}

Person::Person() {
	this->name = new char[1]; // !!! for we use dynamic memory now, there will be differences in terms of the setter + it has to be "destructed"
	this->name[0] = '\0';
	this->age = 0;
}

Person::Person(const Person& other) {
	copy(other);
}

Person& Person::operator=(const Person& other) {
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}

Person::~Person() {
	del();
}

const char* Person::getName() const {
	return this->name;
}

void Person::setName(const char* _name) {
	this->name = new char[strlen(_name) + 1];
	strcpy_s(this->name, strlen(_name) + 1, _name);
}

unsigned Person::getAge() const {
	return age;
}

void Person::setAge(unsigned _age) {
	this->age = _age;
}

bool Person::operator==(const Person& other) {
	return strcmp(this->name, other.name) == 0 && this->age == other.age;
}

bool Person::operator!=(const Person& other) {
	return !(*this == other);
}
