#include <iostream>
#include <fstream>
#include <string>

int main() {

  // WRITING IN A FILE
	//// fstream type and ios::out practice
	//std::fstream myFile;
	//myFile.open("kristina.txt", std::ios::out); // we use this mode, in order to WRITE in a text file
	//if (myFile.is_open()) {
	//	myFile << "Hello!" << std::endl;
	//	myFile << "This is the second line.\n";
	//	myFile.close();
	//}

	//// ios::app (append) practice
	//myFile.open("kristina.txt", std::ios::app); 
	//if (myFile.is_open()) {
	//	myFile << "This is the third line.\n";
	//	myFile.close();
	//}

	// READING from a file
	std::fstream myFile("kristina.txt", std::ios::in); // we use this mode, in order to READ in a text file
	if (myFile.is_open()) {
		std::string line;
		while (std::getline(myFile, line)) { // it reads from MYFILE and stores the current line into LINE
			std::cout << line << std::endl;
		}
		myFile.close();
	}

	return 0;
}
