#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class DynamicArray {
private:
	int* data;
	unsigned size;
	unsigned capacity;

	void copy(const DynamicArray& other);
	void erase();
	void resize(); //enlarging capacity

public:
	DynamicArray();
	DynamicArray(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	~DynamicArray();

	unsigned getSize() const;
	unsigned getAtIndex(const unsigned index) const;
	void setAtIndex(const unsigned index, const int element);
	void push_back(const int& element);
	void print() const;
};
