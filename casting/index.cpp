#include <iostream>
#include <fstream>
#include <string>
#include <vector>

	/*** C++ style casts ***
	 * static_cast : compile-time cast : implicit conversions between types
	 * 		- e.g. int to glot, pointer to void*
	 * dynamic_cast : runtime cast : safely downcast from base class to derived
	 * 		- slower than static_cast
	 * const_cast : removing const or adding const
	 * reinterpret_cast : sorta like static, but does not guarantee preservation of memory location
	 * 		- usually best to avoid?
	 * 		- Wait I get it.. You don't actually convert anything.. you just reinterpret it as something else
	 * 
	 * These to not add funcitonality that C style casts cannot achieve on their own
	 * Rather, they are syntactic sugar..
	 * Makes easier to search for in a code base to find errors
	 * 
	 * Adds compile time checking
	 */

using namespace std;

class Base {
	public:
		Base(){}
		virtual ~Base(){}
};

class Derived : public Base {
	public:
		Derived(){}
		~Derived(){}
};

class AlsoDerived : public Base {
	public:
		AlsoDerived(){}
		~AlsoDerived(){}
};

int main() {
	// C style casts
	double value = 5.25;
	int a = value;	// implicit conversion
	int b = (int) value;	// explicit conversion

	// C++ style casts
	double s = static_cast<int>(value) + 5.3;

	Derived* derived = new Derived();
	Base* base = derived;
	AlsoDerived* ad = dynamic_cast<AlsoDerived*>(base);
	// if base is not derived, will give us null..?




	return 0;
}