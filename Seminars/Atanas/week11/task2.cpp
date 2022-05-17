#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Order {
protected:
	unsigned numOfOrder;
	double price;
	unsigned boughtProducts;
	bool purchaseType; // 0 - cash, 1 - card
public:
	Order() {
		numOfOrder = 0;
		price = 0;
		boughtProducts = 0;
		purchaseType = 0;
	}
	Order(unsigned _numOfOrder, double _price, unsigned _boughtProducts, bool _purchaseType) {
		setNumOfOrder(_numOfOrder);
		setPrice(_price);
		setBoughtProducts(_boughtProducts);
		setPurchaseType(_purchaseType);
	}
	void setNumOfOrder(unsigned _numOfOrder) {
		numOfOrder = _numOfOrder;
	}
	void setPrice(double _price) {
		price = _price;
	}
	void setBoughtProducts(unsigned _boughtProducts) {
		boughtProducts = _boughtProducts;
	}
	void setPurchaseType(bool _purchaseType) {
		purchaseType = _purchaseType;
	}

	void print() const {
		cout << "Number of Order: " << numOfOrder << "\nPrice: " << price << "\nBought Products: " << boughtProducts << "\nPurchase Type /cash - 0, card - 1/: "
			<< purchaseType << endl;
	}
};


// При наложен платеж трябва да фигурира информация за допълнително заплащане за доставка. (при плащане с карта е безплатна) 
//при наложен платеж - изчислената доставка(при закупени артикули под 5бр - 5лв, до 10бр - 10лв и над 10 - 15лв)
class Cash : virtual public Order {
private:
	double extraFee;
public:
	Cash() : Order() { extraFee = 0; }
	Cash(unsigned _numOfOrder, double _price, unsigned _boughtProducts, bool _purchaseType, double _extraFee) 
		: Order(_numOfOrder, _price, _boughtProducts, _purchaseType) {
		extraFee = _extraFee; 
	}
	void print() const {
		Order::print();
		cout << "Extra Fee: " << extraFee << endl;
	}
};

// При плащане с карта трябва да се запазва информация за номер на карта и номер на фактура.
// при плащане с карта - метод за връщане на номер на карта(като се връщат маркирани с * всички цифри без последните 4)

class Card : virtual public Order {
private:
	std::string numOfCard;
public:
	Card() : Order() { numOfCard[0] = '\0'; }
	Card(unsigned _numOfOrder, double _price, unsigned _boughtProducts, bool _purchaseType, std::string _numOfCard)
		: Order(_numOfOrder, _price, _boughtProducts, _purchaseType) {
		setNumOfCard(_numOfCard);
	}
	void setNumOfCard(std::string _numOfCard) {
		if (_numOfCard.length() == 16) {
			numOfCard = _numOfCard;
		}
	}
	void print() const {
		Order::print();
		if (numOfCard[0] != '\0') {
			cout << "Number of card: ";
			for (char symbol : numOfCard) {
				cout << "*";
			}
			cout << endl;
		}
	}
};

int main() {
	Cash cash(27, 40, 1, 0, 3.99);
	cash.print();
	cout << "---------------------------------" << endl;
	Card card(28, 80, 2, 1, "1111222233334444");
	card.print();
	return 0;
}
