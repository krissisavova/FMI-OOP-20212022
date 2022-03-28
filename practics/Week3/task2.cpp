#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

struct Point {
	int x;
	int y;
};

void readPoint(Point& point) {
	cout << "Insert x: ";
	cin >> point.x;
	cout << "Insert y: ";
	cin	>> point.y;
}

void writePointToBinaryFile(const char* filename, Point& point) {
	std::ofstream myBinFile(filename, std::ios::binary);
	if (myBinFile.is_open()) {
		myBinFile.write((const char*)&point, sizeof(Point));
		myBinFile.close();
	}
	else {
		cout << "Failed to open file\n";
		return;
	}
}

void readPointFromBinaryFile(const char* filename) {
	std::ifstream myBinFile(filename, std::ios::binary);
	if (myBinFile.is_open()) {
		Point point;
		myBinFile.read((char*)&point, sizeof(Point));
		myBinFile.close();
		cout << "X: " << point.x << ", Y: " << point.y << endl;
	}
	else {
		cout << "Failed to open file\n";
		return;
	}
}

int main() {
	Point pt;
	readPoint(pt);
	writePointToBinaryFile("task2-test.bin", pt);
	readPointFromBinaryFile("task2-test.bin");
	return 0;
}
