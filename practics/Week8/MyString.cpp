#include "MyString.h"

void MyString::del() {
	delete[] str;
}

void MyString::copy(const MyString& other) {
	size = other.size;
	capacity = other.capacity;
	str = new char[capacity]; // !!!!!!!
	for (unsigned i = 0; i < size; i++) {
		str[i] = other.str[i];
	}
}

void MyString::resize() {
	capacity *= 2;
	char* newStr = new char[capacity];

	for (unsigned i = 0; i < size; i++) {
		newStr[i] = str[i];
	}
	del();
	str = newStr;
}

MyString::MyString() {
	capacity = 8;
	str = new char[capacity + 1];
	size = 0;
}

MyString::MyString(const char* _str, unsigned _size) {
	setStr(_str, _size);
}

MyString::MyString(const MyString& other) {
	copy(other);
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}

MyString::~MyString(){
	del();
}

const char* MyString::getStr() const {
	return str;
}

unsigned MyString::getSize() const {
	return size;
}

unsigned MyString::getCapacity() const {
	return capacity;
}

void MyString::setStr(const char* _str, const unsigned& _size) { // !!!!!!!
	size = _size;
	capacity = size * 2;
	str = new char[capacity];
	for (unsigned i = 0; i < size; i++) {
		str[i] = _str[i];
	}
}

void MyString::changeStr() {

}

void MyString::addSymbolAtEnd(const char symbol) {
	if (size >= capacity) {
		resize();
	}
	str[size++] = symbol;
}

void MyString::addSymbolAtBeg(const char symbol) {
	if (size >= capacity) {
		resize();
	}
	char* newStr = new char[capacity];
	++size;
	newStr[0] = symbol;
	for (unsigned i = 0; i < size; i++) {
		newStr[i] = str[i];
	}
	del();
	setStr(newStr, size);
}

void MyString::addSymbolAtIndex(const char element, const unsigned& position) { // not finished
	if (size >= capacity){
		resize();
	}
	char* newStr = new char[capacity];
	++size;
	unsigned index = 0;
	for (size_t i = 0; i < size; i++) {
		if (position == i) {
			newStr[i] = element;
			//...
		}
	}
	del();
	setStr(newStr, size);
}

MyString MyString::operator+(const MyString& other) const {
	MyString s;
	s.size = size + other.size;
	s.capacity = s.size * 2;
	s.str = new char[s.capacity];
	unsigned index = 0;

	for (unsigned i = 0; i < size; i++) {
		s.str[index++] = str[i];
	}
	for (unsigned i = 0; i < other.size; i++) {
		s.str[index++] = other.str[i];
	}
	return s;
}

MyString& MyString::operator+=(const MyString& rhs) {
	*this = *this + rhs;
	return *this;
}

bool MyString::operator<(const MyString& other) {
	return str < other.str;
}

bool MyString::operator>(const MyString& other) {
	return str > other.str;
}

bool MyString::operator==(const MyString& other) {
	return str == other.str;
}

bool MyString::operator!=(const MyString& other) {
	return !(str == other.str);
}

bool MyString::operator<=(const MyString& other)
{
	return (str == other.str || str < other.str);
}

bool MyString::operator>=(const MyString& other) {
	return (str == other.str || str > other.str);
}

char MyString::operator[](unsigned index) const { // CONST!!!!!!
	if (index > size) {
		std::cout << "Invalid index" << std::endl;
			return '-';
	}
	return str[index];
}

std::ostream& operator<<(std::ostream& out, const MyString& data) {
	out << "My size: " << data.size;
	out << "\nMy string: ";
	for (unsigned i = 0; i < data.size; i++) {
		out << data.str[i];
	}
	return out;
}

std::istream& operator>>(std::istream& in, MyString& data) {
	std::cout << "Enter size: ";
	in >> data.size;
	std::cout << "Enter my string: ";
	for (unsigned i = 0; i < data.size; i++) {
		in >> data.str[i];
	}
	return in;
}
