#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

class Store {
private:
	char* products;
	unsigned size;
	unsigned capacity;

	void copy(const Store& other) {
		setSize(size);
		setCapacity(capacity);
		setProducts(products);
	}

	void del() {
		delete[] products;
	}

	void resize() {
		if (size >= capacity) {
			capacity *= 2;
		}
		// store data in a bigger buffer 
		char* newProducts = new char[this->capacity];
		// copy all data from the previous buffer 
		for (unsigned i = 0; i < size; i++) {
			newProducts[i] = products[i];
		}

		// free allocated memory of this->products[i] and set pointer to newData
		del();
		this->products = newProducts;
	}

public:
	Store() {
		/*this->products = new char[1];
		this->products[0] = '\0';*/
		size = 0;
		capacity = 8;
		products = new char[capacity];
	}

	Store(const char* _products, unsigned _size, unsigned _capacity) : size(_size), capacity(_capacity) {
		products = new char[strlen(_products) + 1];
		strcpy_s(products, strlen(_products) + 1, _products);
	}

	Store(const Store& other) {
		copy(other);
	}

	Store& operator=(const Store& other) {
		if (this != &other) {
			del();
			copy(other);
		}
		return *this;
	}
	~Store() {
		del();
	}

	const char* getProducts() const {
		return products;
	}

	unsigned getSize() const {
		return size;
	}

	unsigned getCapacity() const {
		return capacity;
	}

	void setProducts(const char* _products) {
		products = new char[strlen(_products) + 1];
		strcpy_s(products, strlen(_products) + 1, _products);
	}

	void setSize(unsigned _size) {
		this->size = _size;
	}

	void setCapacity(unsigned _capacity) {
		this->capacity = _capacity;
	}

	bool operator<(const Store& other) {
		return products < other.products&& size < other.size&& capacity < other.capacity;
	}

	bool operator<=(const Store& other) {
		return *this == other || *this < other;
	}

	bool operator>(const Store& other) {
		return !(*this <= other);
	}

	bool operator>=(const Store& other) {
		return *this == other || *this > other;
	}

	bool operator==(const Store& other) {
		return this->size == other.size && this->capacity == other.capacity && (strcmp(this->products, other.products) == 0);
	} 

	bool operator!=(const Store& other) {
		return !(*this == other);
	}

	friend std::ostream& operator<<(std::ostream& out, const Store& store) { // const for OUT
		return out << store.products << " " << store.size << " " << store.capacity << endl;
	}

	friend std::istream& operator>>(std::istream& in, Store& store) { // no const for IN
		in >> store.products >> store.size >> store.capacity;
		return in;
	}

	void addProduct(const char& element) {
		this->products[this->size] = element;
		size++;
	}

	void removeProduct(const char& element) {
		this->products[this->size] = element;
		size--;
	}

	void print() const {
		cout << products << " " << size << " " << capacity << "\n";
	}
};

int main() {
	Store s1("Gosho", 3, 10), s2("Product", 4, 8);
	s1.print();
	cout << s2;
	return 0;
}
