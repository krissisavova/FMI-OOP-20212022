#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Student {
	char name[30];
	unsigned fn;

	struct Date {
		unsigned day;
		unsigned month;
		unsigned year;
	} dateOfBirth;

};

void printStudentInfo(Student& student) {
	cout << student.name << ", " << student.fn << ", "
		<< student.dateOfBirth.day << "." << student.dateOfBirth.month << "." << student.dateOfBirth.year << endl;
}

void swap(Student& st1, Student& st2) {
	Student temp = st1;
	st1 = st2;
	st2 = temp;
}

void sortByFacultyNumbers(Student students[], unsigned size) {
	for (size_t i = 0; i < size - 1; ++i) {
		for (size_t j = 0; j < size - i - 1; ++j) {
			if (students[j].fn > students[j + 1].fn) {
				swap(students[j], students[j + 1]);
			}
		}
	}
}

void printStudentsInfo(Student students[], unsigned size) {
	for (size_t i = 0; i < size; i++) {
		printStudentInfo(students[i]);
	}
}

int main() {

	Student st[3]{
		{"Kristina", 71912, {14, 8, 1994}},
		{"Pesho", 12345, {1, 1, 2001} },
		{"Gosho", 34567, {2, 2, 1992} }
	};

	sortByFacultyNumbers(st, 3);
	printStudentsInfo(st, 3);

	return 0;
}
