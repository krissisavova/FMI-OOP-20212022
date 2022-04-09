#include "ComputerPart.h"

void ComputerPart::copy(const ComputerPart& other) {
	setYearsOfWarranty(other.yearsOfWarranty);
	setPrice(other.price);
	setBrand(other.brand);
	setModel(other.model);
}

void ComputerPart::del() {
	if (brand != nullptr || model != nullptr) {
		delete[] brand;
		delete[] model;
	}
}

ComputerPart::ComputerPart() {
	setYearsOfWarranty(0);
	setPrice(0);
	sizeBrand = 0;
	sizeModel = 0;
	setBrand(nullptr);
	setModel(nullptr);
}

ComputerPart::ComputerPart(Type _typeOfPart, unsigned int _yearsOfWarranty, double _price,
				const char* _brand, const char* _model) : yearsOfWarranty(_yearsOfWarranty), price(_price) {
	setBrand(_brand);
	setModel(_model);
	setType(_typeOfPart);
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
	yearsOfWarranty = _yearsOfWarranty >= 0 ? _yearsOfWarranty : 0;
}

ComputerPart::Type ComputerPart::getType() const {
	return typeOfPart;
}

void ComputerPart::setType(const Type& _typeOfPart) {
	typeOfPart = _typeOfPart;
}

double ComputerPart::getPrice() const {
	return price;
}
void ComputerPart::setPrice(const double& _price) {
	price = _price >= 0 ? _price : 0;
}

unsigned ComputerPart::getSizeBrand() const {
	return sizeBrand;
}
unsigned ComputerPart::getSizeModel() const {
	return sizeModel;
}

const char* ComputerPart::getBrand() const {
	return brand;
}
void ComputerPart::setBrand(const char* _brand) {
	if (_brand == nullptr) {
		return;
	}
	brand = new char[strlen(_brand) + 1];
	strcpy_s(brand, strlen(_brand) + 1, _brand);
}

const char* ComputerPart::getModel() const {
	return model;
}
void ComputerPart::setModel(const char* _model) {
	if (model == nullptr) {
		return;
	}
	model = new char[strlen(_model) + 1];
	strcpy_s(model, strlen(_model) + 1, _model);
}