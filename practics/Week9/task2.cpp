#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Base {
protected:
	unsigned numOfOrder;
	double price;
	unsigned boughtProducts;
	bool typeOfPurchase;
private:
	void copy(const Base& other) {
		numOfOrder = other.numOfOrder;
		price = other.price;
		boughtProducts = other.boughtProducts;
		typeOfPurchase = other.typeOfPurchase;
	}
public:
	Base() {
		numOfOrder = 0;
		price = 0;
		boughtProducts = 0;
		typeOfPurchase = 0; 
	}
	Base(const unsigned& _numOfOrder, const double& _price,
		const unsigned& _boughtProducts, const bool& _typeOfPurchase) {
		numOfOrder = _numOfOrder;
		price = _price;
		boughtProducts = _boughtProducts;
		typeOfPurchase = _typeOfPurchase;
	}
	Base(const Base& other) {
		copy(other);
	}
	Base& operator=(const Base& other) {
		if (this != &other) {
			copy(other);
		}
		return *this;
	}
	void print() const {
		cout << "Preview: \n";
		cout << "Number of order: " << numOfOrder << "\nPrice: " << price
			<< "\nNumber of selected products: " << boughtProducts 
			<< "\nType of purchase /0 - card, 1 - cash/: " << typeOfPurchase << endl;
	}
};

class Card : public Base {
private:
	char numberOfCard[16];
	unsigned numOfInvoice;
public:
	Card() : Base() {
		numberOfCard[0] = '\n';
		numOfInvoice = 0;
	}
	Card(const unsigned& _numOfOrder, const double& _price,
		const unsigned& _boughtProducts, const bool& _typeOfPurchase, const char* _numberOfCard, const unsigned& _numOfInvoice)
		: Base(_numOfOrder, _price, _boughtProducts, _typeOfPurchase) {
		for (unsigned i = 0; i < 16; i++) {
			numberOfCard[i] = _numberOfCard[i];
		}
		numOfInvoice = _numOfInvoice;
	}
	Card(const Card& other) {
		Base::operator=(other);
		for (unsigned i = 0; i < 16; i++) {
			numberOfCard[i] = other.numberOfCard[i];
		}
		numOfInvoice = other.numOfInvoice;
	}

	void print() const {
		Base::print();
		if (typeOfPurchase == 0) {
			cout << "Number of card: ";
			for (unsigned i = 0; i < 12; i++) {
				cout << "*";
			}
			for (unsigned i = 0; i < 4; i++) {
				cout << numberOfCard[i];
			}
			cout << "\nNumber of Invoice: " << numOfInvoice << endl;
		}
		else {
			return;
		}
	}
};

class Cash : public Base {
private:
	unsigned deliveryFee;
public:
	Cash() : Base() {
		deliveryFee = 0;
	}
	Cash(const unsigned& _numOfOrder, const double& _price,
		const unsigned& _boughtProducts, const bool& _typeOfPurchase, const unsigned& _deliveryFee)
		: Base(_numOfOrder, _price, _boughtProducts, _typeOfPurchase) {
		setDeliveryFee();
	}
	Cash(const Cash& other) {
		Base::operator=(other);
		deliveryFee = other.deliveryFee;
	}

	void setDeliveryFee() {
		if (boughtProducts < 5) {
			deliveryFee = 5;
		}
		if (boughtProducts > 5 && boughtProducts <= 10) {
			deliveryFee = 10;
		}
		if (boughtProducts > 10) {
			deliveryFee = 15;
		}
	}

	void print() const {
		Base::print();
		if (typeOfPurchase == 1) {
			cout << "Delivery Fee: " << deliveryFee << endl;
			cout << "Total amount: " << (double)(price + deliveryFee) << endl;
		}
		else {
			return;
		}
	}
};

int main() {
	Base b1(234, 140.99, 2, 0);
	Card p1(234, 140.99, 2, 0, "1234432112344321", 27);
	Cash cash1(235, 250, 12, 1, 4.99), cash2(236, 120.50, 7, 1, 0), cash3(237, 45, 1, 0, 1);
	cout << "BASE TESTING: " << endl;
	b1.print();
	cout << "----------------------------------\n" << endl;

	cout << "CARD TESTING: " << endl;
	p1.print();
	cout << "----------------------------------\n" << endl;

	cout << "CASH TESTING: " << endl;
	cash1.print();
	cout << "----------------------------------\n" << endl;
	cash2.print();
	cout << "----------------------------------\n" << endl;
	cash3.print();
	return 0;
}
