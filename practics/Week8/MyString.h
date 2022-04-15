#pragma once
#include <iostream>

class MyString {
private:
	char* str;
	unsigned size;
	unsigned capacity;

	void del();
	void copy(const MyString& other);
	void resize();

public:
	MyString();
	MyString(const char* _str, unsigned _size);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	const char* getStr() const;
	unsigned getSize() const;
	unsigned getCapacity() const;

	void setStr(const char* _str, const unsigned& _size);

	void changeStr();
	void addSymbolAtEnd(const char symbol);
	void addSymbolAtBeg(const char symbol);
	void addSymbolAtIndex(const char element, const unsigned& position);

	MyString operator+(const MyString& other) const; // CONST!!!!!!
	MyString& operator+=(const MyString& other);
	bool operator<(const MyString& other);
	bool operator>(const MyString& other);
	bool operator==(const MyString& other);
	bool operator!=(const MyString& other);
	bool operator<=(const MyString& other);
	bool operator>=(const MyString& other);
	char operator[](unsigned index) const;

	friend std::ostream& operator<<(std::ostream& out, const MyString& data);
	friend std::istream& operator>>(std::istream& in, MyString& data);
};