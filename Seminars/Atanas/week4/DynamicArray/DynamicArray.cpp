#include "DynamicArray.h"

using std::cin;
using std::cout;
using std::endl;


void DynamicArray::copy(const DynamicArray& other) {
	this->capacity = other.capacity;
	this->size = other.size;
	this->data = new int[this->capacity]; // we already said that this->capacity = other.capacity

	for (unsigned i = 0; i < size; i++) {
		this->data[i] = other.data[i];
	}
}

void DynamicArray::erase() {
	delete[] this->data;
}

void DynamicArray::resize() {
	if (size >= capacity) {
		this->capacity *= 2;
	}
	// store data in a bigger buffer
	int* newData = new int[this->capacity];
	
	// copy all data from the previous buffer
	for (size_t i = 0; i < size; i++) {
		newData[i] = this->data[i];
	}

	// free allocated memory of this->data and set pointer to newData
	this->erase();
	this->data = newData;
}

DynamicArray::DynamicArray() {
	size = 0;
	capacity = 8; // capacity should equal sth that is divisible by 2!
	data = new int[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other) {
	copy(other);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

DynamicArray::~DynamicArray() {
	erase();
}

unsigned DynamicArray::getSize() const {
	return size;
}

unsigned DynamicArray::getAtIndex(const unsigned index) const {
	if (index <= size) {
		return data[index];
	}
	return 0;
}

void DynamicArray::setAtIndex(const unsigned index, const int element) {
	if (index <= size) {
		data[index] = element;
		size++;
	}
}

void DynamicArray::push_back(const int& element) {
	// this check is not necessary if we already have it in the resize() function above
	if(this->data >= capacity || this->data == nullptr) {
		this->resize();
	}
	this->data[this->size] = element;
	size++;	
}

void DynamicArray:: print() const {
	for (size_t i = 0; i < size; i++){
		cout << data[i] << " ";
	}
}
