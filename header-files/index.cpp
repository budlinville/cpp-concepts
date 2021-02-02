#include <iostream>
#include <string>

#include "Box.h"

using namespace std;

/*
	Use this command to build all cpp files in current directory:
		g++ -std=c++11 *.cpp
*/
int main() {
	Box box(4, 5, 6);
	cout << "Volume: " << box.getVolume() << endl;
	cout << "Surface area: " << box.getSurfaceArea() << endl;

	Box* cube = new Box(7, 8, 9);
	cout << "Volume: " << cube->getVolume() << endl;
	cout << "Surface area: " << cube->getSurfaceArea() << endl;

	return 0;
}