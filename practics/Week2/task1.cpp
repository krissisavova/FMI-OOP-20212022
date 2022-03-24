#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

void createFile(const char* filename) {
	std::ofstream outputFile(filename, std::ios::app);
	if (outputFile.is_open()) {
		outputFile << "File successfully created!\n";
		outputFile.close();
	}
}

void printFile(const char* filename) {
	std::ifstream inputName(filename);
	if (inputName.is_open()) {
		std::string line;
		while (std::getline(inputName, line)) {
			cout << line << endl;
		}
		inputName.close();
	}
}

void firstLetters(const char* filename) {
	std::ifstream inputName(filename);
	std::string line;
	std::string result;
	if (inputName.is_open()) {
		while (std::getline(inputName, line)) {
			result += line[0];
		}
		cout << "\nFirst letters of each textfile row: " << result << endl;
		inputName.close();
	}
}

bool renameFile(const char* oldfile, const char* newfile) {
	if (std::rename(oldfile, newfile) == 0) {
		return true;
	}
	return false;
}

bool removeFile(const char* filename) {
	if (std::remove(filename)) {
		return true;
	}
	return false;
}

int main() {
	//createFile("testfile.txt");
	//printFile("testfile.txt");
	//firstLetters("testfile.txt");
	//renameFile("testfile.txt", "testFile.txt");
	removeFile("testFile.txt");

	return 0;
}
