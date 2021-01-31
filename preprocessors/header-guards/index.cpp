#include <iostream>

#include "./square.h"
#include "./geometry.h"

using namespace std;

/* The point here is that if square did not have the header guards, there would be a redeclaration
 * of the getNumSides() method because geometry.h also includes square.h
 * Best practice is to always use header guards
 */
int main() {
	cout << getNumSides() << endl;
	cout << getNumSidesOfSqare() << endl;
	return 0;
}