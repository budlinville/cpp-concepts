#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


// Virtual functions only matter in the context of polymorphism.. That is using a class
// as if it were a derived class
// Also only matters when using 'new' keyword... i.e. pointers
class Foo {
	public: void toString() { cout << "foo" << endl; }
};

class Fee : public Foo {
	public: void toString() { cout << "fee" << endl; }
};

class Bar {
	public: virtual void toString() { cout << "bar" << endl; }
};

class Baz : public Bar {
	// override is unneccessary, but considered best practice
	public: void toString() override { cout << "baz" << endl; }
};

void demoVirtual(Foo* foo, Bar* bar) {
	cout << "Because Foo's toString() IS NOT virtual, the C++ compiler DOES NOT know that this variable may be of a derived type" << endl;
	cout << "Foo: "; foo->toString();
	cout << "Because Bar's toString() IS virtual, the C++ compiler DOES know that this variable may be of a derived type" << endl;
	cout << "Bar: "; bar->toString();
}

int main() {
	// Will print as expected
	Foo* foo1 = new Foo(); foo1->toString();
	Fee* fee1 = new Fee(); fee1->toString();
	Bar* bar1 = new Bar(); bar1->toString();
	Baz* baz1 = new Baz(); baz1->toString();

	// Will get interesting results
	// If I was not using pointers, everything would work as expected
	Fee* fee2 = new Fee();
	Baz* baz2 = new Baz();
	demoVirtual(fee2, baz2);

	return 0;
}