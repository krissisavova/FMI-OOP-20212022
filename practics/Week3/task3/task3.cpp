#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

void createBinaryFileWithContent(const char* filename, const std::string& text) { 
	std::ofstream myBinFile(filename, std::ios::binary);
	if (myBinFile.is_open()) {
		unsigned size = text.size(); // when we wanna use strings, we MUST have some size of it (unsigned variable preferrably)
		myBinFile.write((const char*)&size, sizeof(unsigned));
		myBinFile.write(text.c_str(), size);
		myBinFile.close();
	}
	else {
		cout << "Failed to open file\n";
		return;
	}
}

std::string changeLettersInString(std::string text) {
	unsigned sizeString = text.size();
	for (unsigned i = 0; i < text.size(); ++i) {
		if (islower(text[i])) {
			text[i] = toupper(text[i]);
		}
	}
	return text;
}

int main() {
	std::string changedString = changeLettersInString("KriStInA, krIstiaNA oR kRIStiYanA? That is thE quESTION, isN't It?");
	createBinaryFileWithContent("task3-test.bin", changedString);
	return 0;
}
