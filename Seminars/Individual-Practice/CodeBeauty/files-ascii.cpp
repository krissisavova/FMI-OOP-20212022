#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

// Task: 
// Write some story / long text in a created-in-advance file. 
// Cipher each letter of this text by using the ASCII table and save the final result in a new file. 

int main() {

	// ASCII Code Quick Practice // MAKE IT A COMMENT TO TEST THE OTHER TASKS
	char c1, c2, c3, c4, c5;
	cout << "Enter 5 elements: "; 
	cin >> c1 >> c2 >> c3 >> c4 >> c5;
	cout << "ASCII Code: " << int(c1) << " " << int(c2) << " " << int(c3) << " " << int(c4) << " " << int(c5) << endl;
	

	// ASCII Code Quick Practice 2 // MAKE IT A COMMENT TO TEST THE OTHER TASKS
	std::string word;
	cout << "Give me a word: "; cin >> word;
	for (char& symbol : word) {
		cout << (int)symbol << " ";
	}
	cout << endl;


	// Task // MAKE IT A COMMENT TO TEST THE OTHER TASKS
	std::string line;
	std::fstream storyText("story-text.txt", std::ios::in);
	std::ofstream storyEncoded("story-encrypted.txt", std::ios::out);
	if (storyText.is_open() && storyEncoded.is_open()) {
		while(std::getline(storyText, line)) {
			for (char& symbol : line) {
				storyEncoded << (int)symbol << " ";
			}
		}
		storyText.close();
		storyEncoded.close();
	}

	//std::ifstream storyDecoded("story-encrypted.txt", std::ios::in);
	//if (storyDecoded.is_open()) {
	//	int i = 0;
	//	char str[256];
	//	while (!(str[i] = '\0')) {
	//		for (int& symbol : str) {
	//			cout << (char)symbol << " ";
	//		}
	//	}

	//}

	return 0;
}
