#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;

//Да се дефинира клас Time, който определя момент от денонощието по зададени час и минути.
//Класът да съдържа подходящи методи за :
//
//промяна на часа и минутите с проверки за коректност;
//добавящ към времето цяло число минути;
//достъп до броя минути, изминали от началото на денонощието;
//извеждане на текущия час и минути

class Time {
private:
	unsigned hours;
	unsigned minutes;

public:
	void readTime() {
		cout << "Enter hours: "; cin >> hours;
		while (hours < 0 || hours > 23) {
			cout << "Error! Type another number corresponding to the requirements.\n";
			cout << "Enter hours: "; cin >> hours;
		}

		cout << "Enter minutes: "; cin >> minutes;
		while (minutes < 0 || minutes > 59) {
			cout << "Error! Type another number corresponding to the requirements.\n";
			cout << "Enter minutes: "; cin >> minutes;
		}
	}

	void timeInMinutes() {
		cout << "Total time (in MINUTES) passed from the beginning of the day: " << hours * 60 + minutes << " minutes" << endl;
	}

	void addTime(int newMinutes) {
		if (newMinutes >= 0 && newMinutes <= 60){

			if ((minutes + newMinutes) >= 60) {
				if (hours == 23) {
					hours = 0;
					this->minutes = (minutes + newMinutes) - 60;
				}
				else {
					this->hours++;
					this->minutes = (minutes + newMinutes) - 60;
				}
			}
			else {
				this->minutes += newMinutes;
			}
		}
		else {
			std::cout << "Invalid minutes" << std::endl;
		}
	}

	void print() const {
		if (minutes >= 10 || hours >= 10) {
			cout << "Current time: " << hours << ":" << minutes << endl;
		}
		else {
			cout << "Current time: " << "0" << hours << ":0" << minutes << endl;
		}
	}
};

int main() {
	Time time;
	time.readTime();
	time.print();
	time.timeInMinutes();
	cout << "-----------------------------\n";
	time.addTime(59);
	time.print();
	return 0;
}
