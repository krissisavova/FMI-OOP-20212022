#pragma once
#ifndef FORECAST_H
#define FORECAST_H
#include <iostream>
#include "Temperature.h"

class Forecast {
private:
	char* place;
	unsigned size;
	Temperature temp;

	void copy(const Forecast& other) {
		setPlace(other.place, other.size);
		temp.setMinAvgMax(other.temp.getMin(), other.temp.getAvg(), other.temp.getMax());
	}
	void del() {
		if (place != nullptr) {
			delete[] place;
		}
	}

public:
	Forecast() {
		size = 0;
		place = new char[1];
		place[0] = '\0';
		temp.setMinAvgMax(0, 0, 0);
	}
	Forecast(const char* _place, Temperature const& _temp) {
		setPlace(_place, size);
		temp.setMinAvgMax(_temp.getMin(), _temp.getAvg(), temp.getMax());
	}
	Forecast(const Forecast& other) {
		copy(other);
	} 
	Forecast& operator=(const Forecast& other) {
		if (this != &other) {
			del();
			copy(other);
		}
		return *this;
	}
	~Forecast() {
		del();
	}

	const char* getPlace() const {
		return place;
	}
	unsigned getSize() const {
		return size;
	}

	const Temperature getTemperature() const {
		return temp;
	}

	void setPlace(const char* _place, const unsigned& _size) {
		size = _size >= 0 ? _size : 0;
		place = new char[size];
		for (unsigned i = 0; i < size; i++) {
			place[i] = _place[i];
		}
	}

	/* CHECK THE FOLLOWING THREE AGAIN */
	void updateIfHotter(const Forecast& f) {
		if (place == f.place && temp < f.temp) {
			temp = f.temp;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Forecast& data) {
		out << data.place << ": " << "\nMinimal temperature: " << data.temp.getMin()
								  << "\nAverage temperature: " << data.temp.getAvg() 
								  << "\nMaximal temperature: " << data.temp.getMax();
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Forecast& data) {
		cout << "Insert size: ";
		in >> data.size;
		cout << "Insert name of place: ";
		in >> data.place;
		data.temp.inputTemperatures();
		return in;
	}
};

#endif FORECAST_H
