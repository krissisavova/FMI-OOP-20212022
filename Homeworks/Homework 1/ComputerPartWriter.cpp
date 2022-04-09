#include "ComputerPartWriter.h"

//void ComputerPartWriter::setComputerPart(ComputerPart::Type _type, const char* _brand, const char* _model,
//	unsigned int _yearsOfWarranty, double _price) {
//	cp.setYearsOfWarranty(_yearsOfWarranty);
//	cp.setPrice(_price);
//	cp.setType(_type);
//	cp.setBrand(_brand);
//	cp.setBrand(_model);
//}
//void ComputerPartWriter::saveInfoInFile(const char* filename) {
//	std::ofstream cpWriterFile(filename);
//}

void ComputerPartWriter::printInfo() const {
	std::cout << "{" << cp.getType() << "|" << cp.getBrand() << "|" << cp.getModel() << "|"
		<< cp.getYearsOfWarranty() << "|" << cp.getPrice() << "}" << std::endl;
}
