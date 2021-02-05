#include <iostream>

using namespace std;

void pointTo(int* myPointer) {
	cout << "POINT_TO => was pointing at => " << *myPointer << endl;
	int* newPointer = new int(2);
	myPointer = newPointer;
	cout << "POINT_TO => now pointing at => " << *myPointer << endl;
}

// If you pass a pointer into a function and change where it points do,
// it does not change where the original pointer points to
int main() {
	int* somePointer = new int(1);
	cout << "MAIN => pointing at => " << *somePointer << endl;
	pointTo(somePointer);
	cout << "MAIN => still pointing at => " << *somePointer << endl;
	return 0;
}