#include <iostream>
#include <cstring>
#include <cassert>
using std::cin;
using std::cout;
using std::endl;

class BankAccount {
private:
	char nameOfClient[20];
	char bankAccountNumber[10];
	double principalOfClient;

public:
	const char* getName() {
		return nameOfClient;
	}

	const char* getBankAccountNumber() {
		return bankAccountNumber;
	}

	double getPrincipal() {
		return principalOfClient;
	}
	
	void setName(const char*_nameOfClient) {
		strcpy_s(nameOfClient, _nameOfClient);
	}

	void setBankAccountNumber(const char* _bankAccountNumber) {
		strcpy_s(bankAccountNumber, _bankAccountNumber);
	}

	void setPrincipal(double _principalOfClient) {
		principalOfClient = _principalOfClient;
		assert(principalOfClient >= 0);
	}

	void createBankAccount() {
		cout << "Welcome! Please, enter your name: ";
		cin >> nameOfClient;
		cout << "Enter bank account number: /ALL CAPITAL LETTERS/: ";
		cin >> bankAccountNumber;
		while (bankAccountNumber[0] != 'B' || bankAccountNumber[1] != 'G') {
			cout << "Error! The first two letters should be 'B' and 'G'. Type a correct number. /ALL CAPITAL LETTERS/\n";
			cout << "Enter bank account number: ";
			cin >> bankAccountNumber;
		} 
		cout << "Enter your principal: ";
		cin >> principalOfClient;
		cout << "Thank you for choosing our bank! Enjoy. \n\n";
	}

	void printBankAccount() {
		cout << "INFORMATION ABOUT " << nameOfClient << ": \n" 
			 << "BA NUMBER" << "\t" << "PRINCIPAL\n" 
			 << bankAccountNumber << "\t" << principalOfClient << endl;
	}

	void withdrawMoney() {
		double withdrawal;
		cout << "Withdraw money: ";
		cin >> withdrawal;
		while (withdrawal > principalOfClient) {
			cout << "You do not have enough money!\n";
			cin >> withdrawal;
		}
		principalOfClient -= withdrawal;
		cout << "You withdrew money successfully! You have " << principalOfClient << " in your bank account now.\n";
	}
	void addMoney() {
		double addition;
		cout << "Add money: ";
		cin >> addition;
		principalOfClient += addition;
		cout << "You added money successfully! You have " << principalOfClient << " in your bank account now.\n";
	}
};


int main() {
	BankAccount ba;
	ba.createBankAccount();
	ba.printBankAccount();
	ba.withdrawMoney();
	ba.addMoney();
	ba.printBankAccount();
	return 0;
}
