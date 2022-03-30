#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class MyMoney {
private:
	char nameOfPerson[50];
	double sum;
	unsigned periodOfTime;
	double interestRate;
public:
	MyMoney() {
		nameOfPerson[0] = '\0';
		sum = 10;
		periodOfTime = 1;
		interestRate = 1;
	}

	MyMoney(const char* _nameOfPerson, double _sum, unsigned _periodOfTime, double _interestRate) { // ONE WAY --> : sum(_sum), periodOfTime(_periodOfTime), interestRate(_interestRate){
		setName(_nameOfPerson);
		setSum(_sum);
		setPeriodOfTime(_periodOfTime);
		setInterestRate(_interestRate);
	}

	const char* getName() {
		return nameOfPerson;
	}

	double getSum() {
		return sum;
	}
	
	unsigned getPeriodOfTime() {
		return periodOfTime;
	}

	double getInterestRate() {
		return interestRate;
	}
	
	void setName(const char* _nameOfPerson) {
		strcpy_s(this->nameOfPerson, _nameOfPerson);
	}
	
	void setSum(double _sum) {
		this->sum = _sum;
	}
	
	void setPeriodOfTime(unsigned _periodOfTime) {
		this->periodOfTime = _periodOfTime;
	}

	void setInterestRate(double _interestRate) {
		this->interestRate = _interestRate;
	}

	double calculateSimpleInterest() {
		double simpleInterest = 0;
		for (unsigned i = 1; i <= periodOfTime; i++) {
			simpleInterest = (sum * interestRate * i) / 100;
			cout << "In year " << i << " Simple Interest: " << simpleInterest << endl;
		}
		return simpleInterest;
	}

	void printPersonDepositDetails() {
		cout << "Deposit details of " << nameOfPerson << ": $" << sum << " for " << periodOfTime << " years and with an interest rate of " 
									  << interestRate << "%" << endl;
	}
};

int main() {
	MyMoney person("Steve", 10000, 10, 5);
	cout << "Simple interest: " << person.calculateSimpleInterest() << endl;
	person.printPersonDepositDetails();
	return 0;
}
