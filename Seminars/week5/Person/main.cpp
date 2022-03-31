#include <iostream>
#include <cstring>
#include "Person.h"
using std::cin;
using std::cout;
using std::endl;

int main() {
	Person p1, p2;
	bool areEqual = p1 == p2;
	bool areNotEqual = p1 != p2;
	cout << areEqual << endl;
	cout << areNotEqual << endl;
	return 0;
}
