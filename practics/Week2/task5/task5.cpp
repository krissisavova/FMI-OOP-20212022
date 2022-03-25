#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

//void createFile(const char* filename) {
//	std::ofstream myFile(filename);
//	if (myFile.is_open()) {
//		myFile << "File successfully created\n";
//		myFile.close();
//	}
//}

//void printFile(const char* filename) {
//	std::ifstream myFile(filename);
//	if (myFile.is_open()) {
//		std::string line;
//		while (std::getline(myFile, line)) {
//			cout << line << endl;
//		}
//		myFile.close();
//	}
//}

void reverseLetters(const char* filename) {
	std::ifstream myFile(filename);
	std::ofstream temp("temp.txt");
	if (myFile.is_open() || temp.is_open()) {
		char symbol;
		while (symbol = myFile.get()) {
			if (myFile.eof()) {
				break;
			}
			if (symbol >= 'a' && symbol <= 'z') {
				symbol -= 32;
				temp << symbol;
			}
			else if (symbol >= 'A' && symbol <= 'Z') {
				symbol += 32;
				temp << symbol;
			}
			else {
				temp << symbol;
			}
		}
		myFile.close();
		temp.close();

		if (std::remove(filename) == 0) {
			cout << "file removed!" << endl;
			if (std::rename("temp.txt", filename) == 0) {
				cout << "file renamed!" << endl;
			}
		}
	}
	myFile.close();
	temp.close();
}


int main() {
//	createFile("task5-small-letters.txt");
//	printFile("task5-small-letters.txt");
	reverseLetters("task5-small-letters.txt");

	return 0;
}
