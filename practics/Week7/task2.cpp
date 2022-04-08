#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

//Напишете програма, която има клас Доходи, който съхранява доходите за ден и доходите 
//за месец в две отделни целочислени член данни.Напишете подходящи конструктори и предефинирайте 
//следните оператори :
//
//оператор "+"
//оператор "+="
//оператор "-"
//оператор "-="
//оператор "++": с prefix и postfix
//оператор "/"
//оператор "/="
//оператор "<"
//оператор "<="
//оператор "=="
//оператор "!="

class Income {
private:
	unsigned dayIncome;
	unsigned monthIncome;
public:
	Income() {
		dayIncome = 0;
		monthIncome = 0;
	}
	Income(const unsigned& _dayIncome, const unsigned& _monthIncome) 
		: dayIncome(_dayIncome), monthIncome(_monthIncome) {}

	//оператор "+"
	Income operator+(const Income& other) {
		Income income;
		income.dayIncome = dayIncome + other.dayIncome;
		income.dayIncome = monthIncome + other.monthIncome;
		return income;
	}

	//оператор "+="
	Income& operator+=(const Income& other) {
		dayIncome += other.dayIncome;
		monthIncome += other.monthIncome;
		return *this;
	}

	//оператор "-"
	Income operator-(const Income& other) {
		Income income;
		income.dayIncome = fabs(dayIncome - other.dayIncome);
		income.dayIncome = fabs(monthIncome - other.monthIncome);
		return income;
	}
	
	//оператор "-="
	Income& operator-=(const Income& other) {
		dayIncome -= other.dayIncome;
		monthIncome -= other.monthIncome;
		return *this;
	}
	//оператор "++": с prefix и postfix

	Income& operator++() { //prefix
		++dayIncome;
		++monthIncome;
		return *this;
	}

	Income operator++(int) { //postfix
		Income temp = *this;
		++*this;
		return *this;
	}

	//оператор "/"
	Income operator/(const Income& other) {
		Income income;
		if (other.dayIncome == 0 || other.monthIncome == 0) {
			cout << "Invalid number" << endl;
			return *this;
		}

		income.dayIncome = dayIncome / other.dayIncome;
		income.dayIncome = monthIncome - other.monthIncome;
		return income;
	}
	//оператор "/="
	Income& operator/=(const Income& other) {
		if (other.dayIncome == 0 || other.monthIncome == 0) {
			cout << "invalid number" << endl;
			return *this;
		}
		dayIncome /= other.dayIncome;
		monthIncome /= other.monthIncome;
		return *this;
}
	//оператор "<"
	bool operator<(const Income& other) {
		return (dayIncome < other.dayIncome) && (monthIncome < other.monthIncome);
	}
	//оператор "<="
	bool operator<=(const Income& other) {
		return ((dayIncome < other.dayIncome) || (dayIncome == other.dayIncome)) 
			&& ((monthIncome < other.monthIncome) || (monthIncome == other.monthIncome));
	}

	//оператор "=="
	bool operator==(const Income& other) {
		return (dayIncome < other.dayIncome) && (monthIncome == other.monthIncome);
	}
	//оператор "!="
	bool operator!=(const Income& other) {
		return !(*this == other);
	}

	friend std::ostream& operator<<(std::ostream& out, const Income& data) {
		out << "Income for a day: " << data.dayIncome << "\n"
			<< "Income for a month: " << data.monthIncome << endl;
		return out;
	}

	//practice

	//friend std::istream& operator>>(std::istream& in, Income& data) {
	//	in >> data.dayIncome >> data.monthIncome;
	//	return in;
	//}
};

int main() {
	Income income1;
	Income income2(12, 2000);
	Income income3(5, 500);
	bool isEqual1 = income1 == income2;
	bool isEqual2 = (income1 <= income2);
	bool isEqual3 = income1 < income2;
	bool isEqual4 = income1 != income2;
	cout << "Go: " << isEqual1 << endl;
	cout << "Go: " << isEqual2 << endl;
	cout << "Go: " << isEqual3 << endl;
	cout << "Go: " << isEqual4 << endl;
	cout << income2++ << endl;
	cout << ++income2 << endl;
	cout << income2 + income1 << endl;
	cout << income2 - income1 << endl;
	cout << income2 / income1 << endl;
	income3 += income2;
	cout << income3 << endl;
	income3 -= income2;
	cout << income3 << endl;

	return 0;
}
