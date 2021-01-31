#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// dont have to return anything... because its a reference to the original variable
void makeMeYoung(int* age) {
	cout << "I used to be " << *age << endl;
	*age = 21;
}

void actYourAge(int& age) {
	// NOTE : no dereferencing needed
	age = 39;
}

int main() {
	int myAge = 24;
	char myGrade = 'A';

	cout << "Size of int: " << sizeof(myAge) << endl;
	cout << "Size of char: " << sizeof(myGrade) << endl;
	cout << "My age is located at " << &myAge << endl;

	int* agePtr = &myAge;

	cout << "Address of pointer: " << agePtr << endl;
	cout << "Data at memory address: " << *agePtr << endl; // Use pointer to 'dereference' and extract value at that memory address

	int badNums[5] = {4, 13, 14, 24, 34};
	int* numArrayPtr = badNums;

	cout << "Address: " << numArrayPtr << " Value " << *numArrayPtr << endl;
	numArrayPtr++;	// get next memory address of array
	cout << "Address: " << numArrayPtr << " Value " << *numArrayPtr << endl;
	// Note that an integer takes up 4 bytes, so the memory address of one element
	// in an array should be 4 bytes higher than that of the element preceding it

	// the array name is literally just a pointer to the first value of the array
	cout << "Address: " << badNums << " Value " << *badNums << endl;

	makeMeYoung(&myAge);
	cout << "I'm " << myAge << " years old now." << endl;

	int& ageRef = myAge;
	cout << "myAge : " << myAge << endl;
	ageRef++;
	cout << "myAge : " << myAge << endl;
	actYourAge(myAge);
	cout << "myAge : " << myAge << endl;

	// When to use pointers instead of references....
	// WHEN I DONT WANT TO INITIALIZE A VALUE AT DECLARATION
	// Also can assign a new variable to a pointer.. with a new memory address.
	// The reference will always have the same variable with the same memory address
	// You can change that variable's value, but it is still the same variable
	// 						or
	// IRON CLAD RULE: If I don't need to change what I'm pointing at, use a reference
	// That's why pointers are so great for data structures

	return 0;
}