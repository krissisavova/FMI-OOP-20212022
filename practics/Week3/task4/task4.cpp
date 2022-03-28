#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;

struct Student {
	unsigned fn;
	unsigned passedExams;
	unsigned failedExams;
	double average;
};

void saveStudentsInBinaryFile(const char* filename, const Student* st, const unsigned numOfStudents) {
	std::ofstream myBinFile(filename, std::ios::binary);
	if (myBinFile.is_open()) {
		for (size_t i = 0; i < numOfStudents; i++) {
			myBinFile.write((const char*)&st[i].fn, sizeof(unsigned));
			myBinFile.write((const char*)&st[i].passedExams, sizeof(unsigned));
			myBinFile.write((const char*)&st[i].failedExams, sizeof(unsigned));
			myBinFile.write((const char*)&st[i].average, sizeof(double));
		}
		myBinFile.close();
	}
	else {
		cout << "Failed to open file\n";
		return;
	}
}

void readStudentsFromBinaryFile(const char* filename, const Student* st, const unsigned numOfStudents) {
	std::ifstream myBinFile(filename, std::ios::binary);
	if (myBinFile.is_open()) {
		for (unsigned i = 0; i < numOfStudents; i++) {
			myBinFile.read((char*)&st[i].fn, sizeof(unsigned));
			myBinFile.read((char*)&st[i].passedExams, sizeof(unsigned));
			myBinFile.read((char*)&st[i].failedExams, sizeof(unsigned));
			myBinFile.read((char*)&st[i].average, sizeof(double));
		}
		myBinFile.close();
	}
	else {
		cout << "Failed to open file\n";
		return;
	}
}

unsigned* sorttudentsByGPA(Student* st, const unsigned numOfStudents) { // unsigned*, because we return an array of faculty numbers (the first one belongs to that student, whose GPA is the highest)
	unsigned sortedFNs[100] = {};
	for (unsigned i = 0; i < numOfStudents; i++) {
		sortedFNs[i] = st[i].fn;
	}
	for (unsigned i = 0; i < numOfStudents - 1; i++) {
		for (unsigned j = 0; j < numOfStudents - i - 1; j++) {
			cout << sortedFNs[j] << endl;
			if (sortedFNs[j] > sortedFNs[j+1]) {
				unsigned temp = sortedFNs[j];
				sortedFNs[j] = sortedFNs[j + 1];
				sortedFNs[j + 1] = temp;
			}
		}
	}
	return sortedFNs; // returning the whole array
}
int main() {
	Student students[3]{
				{71912, 5, 2, 5.1},
				{71999, 2, 5, 3.5},
				{62565, 7, 0, 6}
	};
	saveStudentsInBinaryFile("task4-test.bin", students, 3);
	Student studentsFromFile[3];
	readStudentsFromBinaryFile("task4-test.bin", studentsFromFile, 3);

	unsigned* sortedStudents = sorttudentsByGPA(studentsFromFile, 3);

	for (unsigned i = 0; i < 3; i++) {
		cout << sortedStudents[i] << endl;
	}
	return 0;
}
