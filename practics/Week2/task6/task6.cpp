#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

void saveResultsToFile(const char* filename, int result) {
	std::ofstream myFile(filename, std::ios::app);
	if (myFile.is_open()) {
		myFile << result << endl;
		myFile.close();
	}
	else {
		cout << "Failed to open file" << endl;
		return;
 	}
}

int calculateExpression(const char* expression, unsigned size) {
	int firstNumber = 0;
	int secondNumber = 0;
	char op = 'n';
	for (unsigned i = 0; i < size; i++) {
		if (expression[i] >= '0' && expression[i] <= '9') {
			if (op == 'n') {
				firstNumber = firstNumber * 10 + (expression[i] - 48);
				continue;
			}
			secondNumber = secondNumber * 10 + (expression[i] - 48);
		}
		else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
			op = expression[i];
		}
		else {
			std::cout << "Invalid expression" << std::endl;
			return 0;
		}
	}

	switch (op) {
	case '+': return firstNumber + secondNumber;
	case '-': return firstNumber - secondNumber;
	case '*': return firstNumber * secondNumber; 
	case '/': return secondNumber != 0 ? firstNumber / secondNumber : 0; 
	}
}

int main() {
	//createFile("task6-math-expressions.txt");
	//char expression[256] = "35/5";
	//char expression[256] = "35/0";
	//char expression[256] = "35+5";
	//char expression[256] = "35-5";
	char expression[256] = "35*5";
	int result = calculateExpression(expression, 4);
	saveResultsToFile("task6-math-expressions-answers.txt", result);

	return 0;
}
