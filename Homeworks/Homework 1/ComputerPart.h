//А) Да се дефинира клас ComputerPart, описващ артикул в магазин за компютърни части.
//Един артикул се характеризира с:
//тип(монитор, компютър, лаптоп, мишка, клавиатура, слушалки или камера);
//години гаранция – цяло неотрицателно число;
//цена – неотрицателно число с плаваща точка;
//марка – символен низ с произволна дължина;
//модел - символен низ с произволна дължина.
//Да се дефинират подходящи конструктори и методи за достъп до полетата.
//Единствената характеристика, която може да бъде променяна след създаването на обект - артикул е неговата цена.
//Необходимо е данните да бъдат валидирани!

#pragma once
#include <iostream>
#include <cstring>

class ComputerPart {
private:
	enum Type {
		Unknown = -1,

		Computer,
		Laptop,
		Mouse,
		Keyboard,
		Headphones,
		Camera
	} typeOfPart;
	unsigned int yearsOfWarranty;
	double price;
	char* brand; // needs capacity maybe?
	unsigned sizeBrand;			   
	char* model; // needs capacity maybe?
	unsigned sizeModel;

	void copy(const ComputerPart& other);
	void del();

public:
	// the big 4
	ComputerPart();
	ComputerPart(Type _type, unsigned int _yearsOfWarranty, 
				 double _price, const char* _brand, const char* _model);
	ComputerPart(const ComputerPart& other);
	ComputerPart& operator=(const ComputerPart& other);
	~ComputerPart();

	// getters and setters
	// do I need a getter and a setter for type?!?!

	unsigned int getYearsOfWarranty() const;
	void setYearsOfWarranty(const unsigned int& _yearsOfWarranty);

	double getPrice() const;
	void setPrice(const double& _price);

	// do I need setters for the sizes?
	unsigned getSizeBrand() const;
	unsigned getSizeModel() const;

	const char* getBrand() const;
	void setBrand(const char* _brand);

	const char* getModel() const;
	void setModel(const char* _model);

};

