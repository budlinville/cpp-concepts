#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base {
	public:
		Base() { cout << "Base Constructor" << endl; }
		~Base() { cout << "Base Destructor" << endl; }
};

class Derived : public Base {
	public:
		Derived() { cout << "Derived Constructor" << endl; }
		~Derived() { cout << "Derived Destructor" << endl; }
};

class Base2 {
	public:
		Base2() { cout << "Base2 Constructor" << endl; }
		virtual ~Base2() { cout << "Base2 Virtual Destructor" << endl; }
};

class Derived2 : public Base2 {
	public:
		Derived2() { cout << "Derived2 Constructor" << endl; }
		~Derived2() { cout << "Derived2 Destructor" << endl; }
};

void simpleDecl() {
	Derived derived;
}

int main() {
	// base constructor called, then derived
	// on deletion (when it goes out of scope), derived constructor called, then base
	simpleDecl();

	cout << "-----" << endl;
	
	// Problem : derived destructor never gerts called b/c compiler treats it as type Base
	// if we allocate memory in derived constructor, but never delete it in the derived
	// destructor, we have a memory leak
	Base* poly = new Derived();
	delete poly;

	cout << "-----" << endl;

	// Solution : make base destructor virtual
	// different than other virtual methods... in the case of normal methods, making it virtual
	// tells the compiler it may be OVERWRITTEN... with destructors, we're not overwriting the
	// base destructor.. we're saying that the compiler needs to look for both the base and the
	// derived destructors.. so that both can be called
	Base2* poly2 = new Derived2();
	delete poly2;

	return 0;
}