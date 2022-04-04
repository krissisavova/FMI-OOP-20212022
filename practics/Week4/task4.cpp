#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Time {
private:
	unsigned hours;
	unsigned minutes;

public:
	unsigned getHours() const {
		return hours;
	}

	unsigned getMinutes() const {
		return minutes;
	}

	void setHours(const unsigned& _hours) {
		if (_hours < 0 || _hours > 23) {
			cout << "Error! Type another number for hours corresponding to the requirements.\n";
			return;
		}
		hours = _hours;
	}

	void setMinutes(const unsigned& _minutes) {
		if (_minutes < 0 || _minutes > 59) {
			cout << "Error! Type another number for minutes corresponding to the requirements.\n";
			return;
		}
		minutes = _minutes;
	}

	void timeInMinutes() {
		cout << "Total time (in MINUTES) passed from the beginning of the day: " << hours * 60 + minutes << " minutes" << endl;
	}

	void addTime(int newMinutes) {
		if (newMinutes >= 0 && newMinutes <= 60) {

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
		if (hours >= 10 && minutes >= 10) {
			cout << "Current time: " << hours << ":" << minutes << endl;
		}
		else if (hours < 10 && minutes < 10) {
			cout << "Current time: " << "0" << hours << ":0" << minutes << endl;
		}
		else if (hours < 10 && minutes >= 10) {
			cout << "Current time: " << "0" << hours << ":" << minutes << endl;
		}
		else {
			cout << "Current time: " << hours << ":0" << minutes << endl;
		}
	}
};

class Alarm {
private:
	Time alarmTime;

public:
	void setAlarmTime(const unsigned& _hours, const unsigned _minutes) {
		alarmTime.setHours(_hours);
		alarmTime.setMinutes(_minutes);
	}

	void addMinutes(unsigned _addMinutes) {
		alarmTime.addTime(_addMinutes);
	}

	void resetAlarm() {
		alarmTime.setHours(0);
		alarmTime.setMinutes(0);
	}

	void printAlarm() const {
		alarmTime.print();
	}
};

int main() {
	Alarm alarms[3];
	alarms[0].setAlarmTime(12, 34); 
	alarms[0].printAlarm();

	alarms[1].setAlarmTime(2, 34);
	alarms[1].printAlarm();

	alarms[2].setAlarmTime(9, 0);
	alarms[2].printAlarm();

	return 0;
}
