#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;

//Напишете програма, която има клас, който ще пази таен код. Класът нека да съдържа символ и 
//произволна стойност от целочислен тип. Напишете подходящи конструктори и предефинирайте следните оператори :
//
//оператор "*"
//оператор "*="
//оператор "<<" : принтира кода като първо поставя символа после цифрите
//оператор ">>"

class SecretCode {
private:
	char secretCode;
	unsigned number;

public:
	SecretCode operator*(const SecretCode& secret) {
		SecretCode sc;
		sc.number = number * secret.number;
		return sc;
	}

	SecretCode& operator*=(const SecretCode sc) {
		number = sc.number * number;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const SecretCode& data) {
		out << "String: " << data.secretCode << " w/ number: " << data.number << endl;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, SecretCode& data) {
		in >> data.secretCode >> data.number;
		return in;
	}
};

int main() {
	SecretCode sc1, sc2;
	cin >> sc1;
	cin >> sc2;
	cout << sc1;
	cout << sc2;
	return 0;
}
