#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

class Ticket {
private:
	char placeOfDeparture[30];
	char placeOfArrival[30];
	unsigned yearOfIssue;
	double price;

public:
	Ticket() {
		placeOfDeparture[0] = '\0';
		placeOfArrival[0] = '\0';
		yearOfIssue = 2000;
		price = 0;
	}
	Ticket(const char* _placeOfDeparture, const char* _placeOfArrival, unsigned _yearOfIssue, double _price) : yearOfIssue(_yearOfIssue), price(_price) {
		setPlaceOfDeparture(_placeOfDeparture);
		setPlaceOfArrival(_placeOfArrival);
	}

	const char* getPlaceOfDeparture() const {
		return placeOfDeparture;
	}
	const char* getPlaceOfArrival() const {
		return placeOfArrival;
	}
	unsigned getYearOfIssue() const {
		return yearOfIssue;
	}
	double getPrice() const {
		return price;
	}

	void setPlaceOfDeparture(const char* _placeOfDeparture) {
		strcpy_s(placeOfDeparture, _placeOfDeparture);
	}
	void setPlaceOfArrival(const char* _placeOfArrival) {
		strcpy_s(placeOfArrival, _placeOfArrival);
	}
	void setYearOfIssue(unsigned _yearOfIssue) {
		yearOfIssue = _yearOfIssue;
	}
	void setPrice(double _price) {
		price = _price;
	}

	void printTicketInfo() {
		cout << "Place of Departure: " << "\t" << placeOfDeparture
			<< "\nPlace of Arrival: " << "\t" << placeOfArrival
			<< "\nYear of Issue: " << "\t" << yearOfIssue
			<< "\nPrice: " << "\t" << price << endl;
	}

	char* fixLettersInPlaceOfDep() {
		unsigned len = strlen(placeOfDeparture);
		for (unsigned i = 0; i < len; i++) {
			if (islower(placeOfDeparture[0])) {
				placeOfDeparture[0] = toupper(placeOfDeparture[0]);
			} 
			if (isupper(placeOfDeparture[i])) {
				placeOfDeparture[i] = tolower(placeOfDeparture[i]);
			}
		}
		return placeOfDeparture;
	}

	char* fixLettersInPlaceOfArr() {
		unsigned len = strlen(placeOfArrival);
		for (unsigned i = 0; i < len; i++) {
			if (islower(placeOfArrival[0])) {
				placeOfArrival[0] = toupper(placeOfArrival[0]);
			}
			if (isupper(placeOfArrival[i])) {
				placeOfArrival[i] = tolower(placeOfArrival[i]);
			}
		}
		return placeOfArrival;
	}
};

int main() {
	Ticket t1("bURGAs", "BLAgoEVgrad", 2021, 25);
	Ticket t2("SOFia", "varNa", 2022, 20);
	t1.fixLettersInPlaceOfDep();
	t1.fixLettersInPlaceOfArr();
	t2.fixLettersInPlaceOfDep();
	t2.fixLettersInPlaceOfArr();

	t1.printTicketInfo();
	cout << endl;
	t2.printTicketInfo();

	return 0;
}

