#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Animal{
	public:
		void getFamily() { cout << "We are animals" << endl; }
		// base-class method that MAY be overwritten by a subclass
		virtual void getClass(){ cout << "I'm an Animal" << endl; }
};

class Dog : public Animal{
	public:
		void getClass() { cout << "I'm a Dog" << endl; }
};

class GermanShepard : public Dog{
	public:
		void getClass() { cout << "I'm a German Shepard" << endl; }
		void gerDerived() { cout << "I'm an Animal and Dog"; }
};

// If getClass is not declared as a virtual function, this will print "I'm an animal"
// regardless of whether a dog or an animal was passed into it
void whatClassAreYou(Animal *animal) {
	animal->getClass();
}

int main(){
	// side-noteL parentheses are optional on this declaration..
	Animal *animal = new Animal();
	Dog *dog = new Dog;

	animal->getClass();
	dog->getClass();

	// would expect to get the same results as above.. but we don't
	whatClassAreYou(animal);
	whatClassAreYou(dog);

	cout << "---------------------------" << endl;

	Dog spot;
	GermanShepard max;
	Animal* ptrDog = &spot;
	Animal* ptrGShepard = &max;

	ptrDog->getFamily();
	ptrDog->getClass();
	ptrGShepard->getFamily();
	ptrGShepard->getClass();

	return 0;
}