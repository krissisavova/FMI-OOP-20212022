#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

void createBinaryFileWithNum(const char* filename, const unsigned number) {
	std::ofstream myFile(filename, std::ios::binary);
	if (myFile.is_open()) {
		myFile.write((const char*)&number, sizeof(unsigned));
		myFile.close();
	}
	else {
		cout << "Failed to open file\n";
	}
}

void createBinaryFileWithChar(const char* filename, const char symbol) {
	std::ofstream myFile(filename, std::ios::binary);
	if (myFile.is_open()) {
		myFile.write(&symbol, sizeof(char));
		myFile.close();
	}
	else {
		cout << "Failed to open file\n";
	}
}

unsigned getNumberFromBinaryFile(const char* filename) {
	std::ifstream myFile(filename, std::ios::binary);
	unsigned number = 0;
	if (myFile.is_open()) {
		myFile.read((char*)&number, sizeof(unsigned));
		myFile.close();
	}
	else {
		cout << "Failed to open file\n";
	}
	return number;
}

char getCharFromBinaryFile(const char* filename) {
	std::ifstream myFile(filename, std::ios::binary);
	char symbol = ' ';
	if (myFile.is_open()) {
		myFile.read(&symbol, sizeof(char));
		myFile.close();
	}
	else {
		cout << "Failed to open file\n";
	}
	return symbol;
}

int main() {
	createBinaryFileWithNum("testBinaryFile.bin", 27);
	cout << getNumberFromBinaryFile("testBinaryFile.bin");
	createBinaryFileWithChar("testBinaryFile.bin", 'K');
	cout << getCharFromBinaryFile("testBinaryFile.bin");

	return 0;
}
