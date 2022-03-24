#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

//void createFile(const char* filename) {
//	std::ofstream myFile(filename);
//	if (myFile.is_open()) {
//		myFile << "This is how the file starts...\n";
//		myFile.close();
//	}
//}

void readTwoFiles(const char* filename1, const char* filename2) {
	std::ifstream contentFile1(filename1);
	std::ifstream contentFile2(filename2);
	std::ofstream resultFile("task3-content-from-two-files.txt");

	if (contentFile1.is_open() || contentFile2.is_open() || resultFile.is_open()) {
		std::string line;
		while (std::getline(contentFile1, line)) {
			resultFile << line << endl;
		}
		while (std::getline(contentFile2, line)) {
			resultFile << line << endl;
		}
		resultFile.close();
		contentFile1.close();
		contentFile2.close();
	}
}

int main() {
	//createFile("task3-contentFile2.txt");
	readTwoFiles("task3-contentFile1.txt", "task3-contentFile2.txt");
	return 0;
}
