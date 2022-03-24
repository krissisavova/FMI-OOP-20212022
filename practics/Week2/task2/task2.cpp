#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

//void createFile(const char* filename) {
//	std::ofstream myFile(filename);
//	if (myFile.is_open()) {
//		myFile << "2 3 5 7 9 8 5 34 23\n";
//		myFile.close();
//	}
//}

//void printFile(const char* filename) {
//	std::ifstream myFile(filename);
//	if (myFile.is_open()) {
//		std::string line;
//		while (std::getline(myFile, line)) {
//			cout << line;
//		}
//		myFile.close();
//	}
//}

void readFile(const char* filename) {
	std::ifstream numbersFile(filename);
	std::ofstream oddNumbers("oddFile.txt");
	std::ofstream evenNumbers("evenFile.txt");

	if (!numbersFile.is_open() || !oddNumbers.is_open() || !evenNumbers.is_open()) {
		cout << "Failed to Open File(s)\n";
		return;
	}
	
	int currentNumber;
	while (numbersFile >> currentNumber) {
		if (currentNumber % 2 == 0) {
			evenNumbers << currentNumber << " ";
		}
		else {
			oddNumbers << currentNumber << " ";
		}
	}
	numbersFile.close();
	oddNumbers.close();
	evenNumbers.close();
}

int main() {

	//printFile("file-with-numbers.txt");
	readFile("file-with-numbers.txt");
	return 0;
}
