#include <iostream>
#include "DynamicArray.cpp"
using std::cin;
using std::cout;
using std::endl;

int main() {
  
	DynamicArray* arr = new DynamicArray();
	arr->setAtIndex(0, 1);
	arr->setAtIndex(7, 15);
	arr->setAtIndex(3, 13);
	arr->setAtIndex(20, 31);
	return 0;
}
