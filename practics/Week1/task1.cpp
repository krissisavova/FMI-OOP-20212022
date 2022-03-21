#include <iostream>
using std::cin;
using std::cout;
using std::endl;

enum Gender {
	Male,
	Female,
	Other
};

struct Person {
	char name[50];
	unsigned age;
	Gender gender;
};

void printPersonInfo(Person& person) {
	cout << person.name << ", " << person.age << " --> ";
	switch (person.gender) {
	case Male: cout << "Male" << endl; break;
	case Female: cout << "Female" << endl; break;
	case Other: cout << "Other" << endl; break;
	default: cout << "Unknown" << endl; break;
	}
}

void outputByGender(Person people[], unsigned size, Gender gender) {
	
	for (size_t i = 0; i < size; ++i){
		if (people[i].gender == gender) {
			printPersonInfo(people[i]);
		}
	}
}

int main() {
	Person person[5] {
		{"Kristina", 22, Female},
		{"Gosho", 20, Male},
		{"Joe", 28, Other},
		{"Elizabeth", 27, Female},
		{"Michael", 36, Male}
	};

	Gender gender = Female;

	outputByGender(person, 5, gender);

	return 0;
}
