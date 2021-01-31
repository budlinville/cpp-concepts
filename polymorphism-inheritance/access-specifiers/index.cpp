#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/*******************************
 * Demo of Access Specifiers
 *******************************/

class Base {
	public:
		int x;
		Base() {
			x=1;
			y=2;
			z=3;
		}
		void printProtectedData() {
			cout << "Y: " << y << endl;
		}
		void printPrivateData() {
			cout << "Z: " << z << endl;
		}
	protected:
		int y;
		// Private is always private, regarless of access specifiers
	private:
		int z;
};

class Derived_Public : public Base{
	public:
		void printDerived() {
			cout << "Derived Y: " << this->y << endl;
		}
};

class Derived_Protected : protected Base{};
class Derived_Private : private Base{};
class Derived_Derived_Protected : public Derived_Protected{
	public:
		void printDerivedDerived() {
			cout << "-----------" << endl;
			// This will work, because x and y are protected in Derived_Protected
			// Therefore Derived_Derived_Protected can access them
			cout << "DD-Protected X: " << this->x << endl;
			cout << "DD-Protected Y: " << this->y << endl;
			cout << "GOOD" << endl;
		}
};
class Derived_Derived_Private : public Derived_Private{
	public:
		void printDerivedDerived() {
			cout << "-----------" << endl;
			// This will NOT work, because x and y are private in Derived_Private
			// Therefore Derived_Derived_Private CANNOT access them
			//cout << "DD-Protected X: " << this->x << endl;
			//cout << "DD-Protected Y: " << this->y << endl;
			cout << "BAD" << endl;
		}
};

void printValuesFromOutsideClass(Base obj) {
	// can access public variables directly
	cout << "X: " << obj.x << endl;
	// need public methods to access private and protected variables
	obj.printProtectedData();
	obj.printPrivateData();
}

int main(){
	Base obj1;
	printValuesFromOutsideClass(obj1);

	Derived_Public obj2;
	// derived class has access to base's protected variables
	obj2.printDerived();

	Derived_Protected obj3;
	// This no longer works because x is now PROTECTED in the derived class
	// cout << obj3.x << endl;

	Derived_Private obj4;
	// This no longer works because x is now PRIVATE in the derived class
	// cout << obj3.x << endl;

	Derived_Derived_Protected obj5;
	obj5.printDerivedDerived();

	Derived_Derived_Private obj6;
	obj6.printDerivedDerived();

	return 0;
}
