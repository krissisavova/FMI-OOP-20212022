#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class NumbersSummator {
private:
	double sum;
	unsigned changing;

public:
	NumbersSummator(const double& _sum) {
		setSum(_sum);
		setChanging(0);
	}

	int sum() const {
		return sum;
	}

	void setSum(const double& _sum) {
		sum = _sum;
	}

	unsigned num() const {
		return changing;
	}

	void setChanging(unsigned _changing) {
		this->changing = _changing;
	}

	void add(const double& addition) {
		sum += addition >= 0 ? addition : 0;
		changing++;
	}

	void sub(const double& subtraction) {
		sum -= subtraction >= 0 ? subtraction : 0;
		changing++;
	}
	void printSum() const {
		cout << "SUM: " << sum << endl;
	}
};

int main() {
	NumbersSummator s(23);
	s.add(3);
	s.sub(2);
	cout << s.num();
	s.printSum();
	return 0;
}
