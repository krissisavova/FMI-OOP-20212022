#include <iostream>
#include <cstring>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_PRODUCTS = 10;

class Product {
private:
	char nameOfProduct[30];
	double price;
	unsigned shelfLife;
	unsigned percentageOfFats;
	bool isFood;

public:
	Product() {
		setNameOfProduct(" ");
		setShelfLife(0);
		setPercentageOfFats(0);
		setIsFood(0);
	}
	Product(const char* _nameOfProduct, unsigned _shelfLife, unsigned _percentageOfFats, bool _isFood) : shelfLife(_shelfLife), percentageOfFats(_percentageOfFats), isFood(_isFood) {
		strcpy_s(nameOfProduct, _nameOfProduct);
	}

	const char* getNameOfProduct() const {
		return nameOfProduct;
	}

	double getPrice() const {
		return price;
	}

	unsigned getShelfLife() const {
		return shelfLife;
	}

	unsigned getPercentageOfFats() const {
		return percentageOfFats;
	}

	bool getIfFood() const {
		return isFood;
	}

	void setNameOfProduct(const char* _nameOfProduct) {
		strcpy_s(nameOfProduct, _nameOfProduct);
	}

	void setPrice(double _price) {
		price = _price;
	}

	void setShelfLife(unsigned _shelfLife) {
		shelfLife = _shelfLife;
	}

	void setPercentageOfFats(unsigned _percentageOfFats) {
		percentageOfFats = _percentageOfFats;
	}

	void setIsFood(bool _isFood) {
		isFood = _isFood;
	}

	void printProductInfo() const {
		cout << "Name of product: " << nameOfProduct << ", expires in " << shelfLife << " days, percentage of fats: " << percentageOfFats << "%" << endl;
	}
};

class Store {
private:
	Product products[MAX_PRODUCTS];
	unsigned numOfProducts;
	double currMoney;

public:
	Store() {
		setNumOfProducts(-1);
		setCurrMoney(-1);
	}

	Store(unsigned _numOfProducts, double _currMoney) {
		setNumOfProducts(_numOfProducts);
		setCurrMoney(_currMoney);
	}

	unsigned getNumOfProducts() const {
		return numOfProducts;
	}

	double getCurrMoney() const {
		return currMoney;
	}

	void setNumOfProducts(unsigned _numOfProducts) {
		this->numOfProducts = _numOfProducts;
	}

	void setCurrMoney(double _currMoney) {
		this->currMoney = _currMoney;
	}

	void setProducts(const Product _products[]) {
		for (unsigned i = 0; i < numOfProducts; i++) {
			products[i] = _products[i]; //in case there is a predefined operator=
		}
	}

	void printProducts() {
		for (unsigned i = 0; i < numOfProducts; i++) {
			products[i].printProductInfo();
		}
	}

	void findProduct(const char* word) {
		for (unsigned i = 0; i < numOfProducts; i++) {
			if (strcmp(products[i].getNameOfProduct(), word) == 0) {
				products[i].printProductInfo();
				cout << "________________________________________";
				return;
			}
		}
	}

	double calculationLosses() {
		double losses = 0;
		for (unsigned i = 0; i < numOfProducts; i++) {
			if (products[i].getShelfLife() <= 0) {
				losses += products[i].getPrice();
			}
		}
		currMoney -= losses;
		return losses;
	}

	void sellProduct(unsigned index) {
		if (index >= numOfProducts) {
			cout << "No Products Left\n";
			return;
		}
		for (unsigned i = 0; i < numOfProducts; i++) {
			if (index == i) {
				cout << "Selling product " << products[i].getNameOfProduct() << endl;
			}
		}

		// A, B, C, anabol, D -> remove index=3
		// A, B, C, D ?

		//Moving the rest of the elements in the array 1 position to the left
		for (unsigned i = index; i + 1 != numOfProducts; i++) { 
			products[i] = products[i + 1];
		}
		// A, B, C, D, D -> (default values)
	}
};

int main() {

	return 0;
}
