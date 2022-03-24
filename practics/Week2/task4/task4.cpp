#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

//void createFile(const char* filename) {
//	std::ofstream myFile(filename);
//	if (myFile.is_open()) {
//		myFile << "File successfully created" << endl;
//		myFile.close();
//	}
//}

//bool renameFile(const char* filename1, const char* filename2) {
//	if (std::rename(filename1, filename2) == 0) {
//		return true;
//	}
//	return false;
//}

void removeEmptyRows(const char* filename) {
	std::ifstream myFile(filename);
	std::ofstream tempFile("temp.txt");

	if (myFile.is_open()) {
		std::string line;
		while (std::getline(myFile, line)) {
			if (line != "") {
				tempFile << line << endl;
			}
		}
		myFile.close();
		tempFile.close();
		if (std::remove(filename) == 0) {
			cout << "File removed successfully!\n";
			if (std::rename("temp.txt", filename) == 0) {
				cout << "File successfully renamed" << endl;
			}
		}
	}
}

int main() {
	//createFile("task4-no-spaces.txt");
	//renameFile("task4-no-spaces.txt", "task4-no-empty-rows.txt");

	removeEmptyRows("task4-no-empty-rows.txt");
	return 0;
}
