#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

// week 5 / task 2
//Да се дефинира клас Word, описващ дума, с произволна дължина.Класът да съдържа следните операции :
//
//метод за намиране на i - тия пореден символ в думата
//метод за добавяне на един символ в края на думата.
//метод за сравнение на думи спрямо лексикографската наредба
//подходящи конструктори

// week 7 / task 3

//Използвайки условието за класа Word от week5 - описващ дума.
//Изменете класа да има дума от точно 256 символа.Предефинирайте:
//
//оператор "+" : конкатенация на две думи
//оператор "<<" : извеждане на думата в конзолата
//оператор ">>" : въвеждане на дума от конзолата
//Опитайте да предефинирате операторите ако думата е с произволна дължина

class Word {
private:
	char word[256];
public:
	Word operator+(const Word& other) {
		strcat_s(word, other.word);
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, const Word& data) {
		return out << "Word: " << data.word << endl;
	}
	friend std::istream& operator>>(std::istream& in, Word& data) {
		return in >> data.word;
	}
};

int main() {
	Word word1, word2;
	Word result;
	cout << "Enter two words: ";
	cin >> word1;
	cin >> word2;
	result = word1 + word2;
	cout << result;
	return 0;
}
