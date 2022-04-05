#include "ComputerPart.h"

void ComputerPart::copy(const ComputerPart& other) {
	setYearsOfWarranty(other.yearsOfWarranty);
	setPrice(other.price);
	setBrand(other.brand);
	setModel(other.model);
}

void ComputerPart::del() {
	if (this->brand != nullptr || this->model != nullptr) {
		delete[] brand;
		delete[] model;
	}
}

ComputerPart::ComputerPart() {
	setYearsOfWarranty(0);
	setPrice(0);
	this->sizeBrand = 0;
	this->sizeModel = 0;
	setBrand(nullptr);
	setModel(nullptr);
}

ComputerPart::ComputerPart(Type _type, unsigned int _yearsOfWarranty, double _price,
				const char* _brand, const char* _model) : yearsOfWarranty(_yearsOfWarranty), price(_price) {
	setBrand(_brand);
	setModel(_model);
}

ComputerPart::ComputerPart(const ComputerPart& other) {
	copy(other);
}

ComputerPart& ComputerPart::operator=(const ComputerPart& other) {
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}

ComputerPart::~ComputerPart() {
	del();
}

unsigned int ComputerPart::getYearsOfWarranty() const {
	return yearsOfWarranty;
}
void ComputerPart::setYearsOfWarranty(const unsigned int& _yearsOfWarranty) {
	this->yearsOfWarranty = _yearsOfWarranty >= 0 ? _yearsOfWarranty : 0;
}

double ComputerPart::getPrice() const {
	return this->price;
}
void ComputerPart::setPrice(const double& _price) {
	this->price = _price >= 0 ? _price : 0;
}

unsigned ComputerPart::getSizeBrand() const {
	return this->sizeBrand;
}
unsigned ComputerPart::getSizeModel() const {
	return this->sizeModel;
}

const char* ComputerPart::getBrand() const {
	return this->brand;
}
void ComputerPart::setBrand(const char* _brand) {
	// additional checks needed
	this->brand = new char[strlen(_brand) + 1];
	strcpy_s(this->brand, strlen(_brand) + 1, _brand);
}

const char* ComputerPart::getModel() const {
	return model;
}
void ComputerPart::setModel(const char* _model) {
	// additional checks needed
	this->model = new char[strlen(_model) + 1];
	strcpy_s(this->model, strlen(_model) + 1, _model);
}

