#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "golf.cpp"

using namespace std;

int getRand(int min, int max) {
	return (rand() % max) + min;
}

int main() {
	Golf golfy;
	// How to access static vs non-static variables/methods of structs/classes
	cout << golfy.game << endl;
	cout << Golf::greeting << endl;

	for (int i = 0; i < 18; i++) {
		Golf golf;
		int par = getRand(3, 3);
		int shot = getRand(1, 5);
		cout << "Hole " << i+1 << ": ";
		switch (shot) {
			case 1 : golf.eagle(par); break;
			case 2 : golf.birdie(par); break;
			case 3 : golf.par(par); break;
			case 4 : golf.bogie(par); break;
			case 5 : golf.doubleBogie(par); break;
			default: cout << "ERROR: "; golf.par(par); break;
		}
	}

	cout << "----------" << endl << "Par was " << Golf::getPar() << "; You shot " << Golf::getScore() << endl;

	return 0;
}
