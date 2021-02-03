#include <iostream>
#include <string>

using namespace std;

int main() {
	// const with pointers
	const int* a = new int;		// const int* === int const*
	int* b = new int(9);
	cout << "a: " << a << "; *a: " << *a << endl;
	cout << "b: " << b << "; *b: " << *b << endl;

	a = b;
	cout << "a: " << a << "; *a: " << *a << endl;
	cout << "b: " << b << "; *b: " << *b << endl;

	// But wait, a is const.. why can I reassign its value
	// const with pointers means that the value at the memory address cannot change..
	// ..not that I cant change which pointers point to it

	const int* c = new int(8);
	//*c = 7;	// won't work

	const int* d = c;
	//*d = 8;	// also won't work b/c it points to that same memory address

	// Easy, right? Don't worry, it gets more confusing
	int* const e = new int(11);
	*e = 12;
	cout << "e: " << e << "; *e: " << *e << endl;

	// Why does that work?.. Well, if const comes after the '*', it DOES mean that the pointer
	// can/t change, BUT the value at the memory address being pointed to can

	//e = new int(12);	// won't work
	//e = nullptr;	// won't work

	return 0;
}