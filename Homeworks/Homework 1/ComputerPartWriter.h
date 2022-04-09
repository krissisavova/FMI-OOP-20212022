//Да се дефинира помощен клас ComputerPartWriter, който получава артикул и го записва 
//в указан текстов файл със следния формат:
//{<тип> | <марка> | <модел> | <гаранция> | <цена>}.
//Пример:
//{MONITOR | Samsung | C27F390FHR | 5 | 250}

#pragma once 
#include "ComputerPart.h"

class ComputerPartWriter {
private:
	ComputerPart cp;
public:
	//void setComputerPart(ComputerPart::Type _type, const char* _brand, const char* _model,
	//	unsigned int _yearsOfWarranty, double _price);
//	void saveInfoInFile(const char* filename);
	void printInfo() const;
};

