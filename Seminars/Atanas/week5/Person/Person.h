#pragma once
class Person {
private:
	char* name;
	unsigned age;

	void del();
	void copy(const Person& other);

public:
	Person();
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();
	const char* getName() const;
	void setName(const char* _name);
	unsigned getAge() const;
	void setAge(unsigned _age);
	bool operator==(const Person& other);
	bool operator!=(const Person& other);
};

