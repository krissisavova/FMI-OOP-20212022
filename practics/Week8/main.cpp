#include <iostream>
#include "MyString.h"
using std::cout;
using std::cin;
using std::endl;

// create a program which creates an array with a random size
// constructors, methods and operators...

int main() {
	MyString ms;
	cin >> ms;
	cout << ms;
	ms.addSymbolAtBeg('K');
	cout << ms;
	return 0;
}