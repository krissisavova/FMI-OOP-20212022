#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Temperature {
private:
	int min;
	int avg;
	int max;
public:
	Temperature() : min(12), avg(12), max(12) {}
	Temperature(int min, int avg, int max) {
		setMinAvgMax(min, avg, max);
	}
	int getMin() const {
		return min;
	}
	int getAvg() const {
		return avg;
	}
	int getMax() const {
		return max;
	}
	void setMinAvgMax(int min, int avg, int max) {
		this->min = (min <= avg && avg <= max) ? min : 12;
		this->avg = (min <= avg && avg <= max) ? avg : 12;
		this->max = (min <= avg && avg <= max) ? max : 12;
	}

	bool operator==(const Temperature& other) {
		return (min == other.min) && (avg == other.avg) && (max == other.max);
	}
	bool operator!=(const Temperature& other) {
		return !(*this == other);
	}
	bool operator<(const Temperature& other) {
		return (max < other.max)
			|| (max == other.max && min < other.min)
			|| (min == other.min && max == other.max && avg < other.avg);
	}
	bool operator>(const Temperature& other) {
		return (max > other.max)
			|| (max == other.max && min > other.min)
			|| (min == other.min && max == other.max && avg > other.avg);
	}
	bool operator<=(const Temperature& other) {
		return (*this == other) || (*this < other);
	}
	bool operator>=(const Temperature& other) {
		return (*this == other) || (*this > other);
	}
	friend std::ostream& operator<<(std::ostream& out, const Temperature& data) {
		return out << "(" << data.min << ", " << data.avg << ", " << data.max << ")\n";
	}
};

int main() {
	Temperature t1, t2(-20, -21, -2);
	cout << t1;
	cout << t2;
	bool comparingTemperatures = t2 == t1;
	cout << comparingTemperatures << endl; // should return 1, for t2 contains an invalid value
	return 0;
}
