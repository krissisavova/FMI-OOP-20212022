#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template<typename T>
void input(T* array1, int n) {
	cout << "Insert values of the array: \n";
	for (unsigned i = 0; i < n; i++) {
		cout << "array[" << i << "] = ";
		cin >> array1[i];
	}
}

int main() {
	int arr1[7];
	double arr2[10];
	input(arr1, 7);
	cout << ".........." << endl;
	input(arr2, 10);
	return 0;
}
