#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template<typename T>
bool ordered(T* array, int n) {
	for (unsigned i = 0; i < n; i++) {
		if (array[i] < array[i + 1]) {
			if (array[n - 2] < array[n - 1]) {
				return true;
			}
			continue;
		}
		else if (array[i] >= array[i+1]) {
			return false;
		}
		return true;
	}
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int arr2[] = {1, 2, 3, 4, 5, 6, 7};
	cout << ordered(arr2, 7) << endl;
	double arr3[] = {3.4, 4.5, 6.7, 9.0};
	cout << ordered(arr3, 4);
	return 0;
}
