#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Animal{
	public:
		virtual void makeSound(){ cout << "The Animal says grr" << endl; }
};

// what would happen if I put private or protected here??
class Dog : public Animal{
	public:
		virtual void makeSound(){ cout << "The Dog says woof" << endl; }
};

class Cat : public Animal {
	public:
		virtual void makeSound(){ cout << "The Car says meow" << endl; }
};

// Abstract data type
class Car{
	public:
		virtual void getNumWheels() = 0;
		virtual void getNumDoors() = 0;
};

class StationWagon : public Car {
	public:
		void getNumWheels(){ cout << "Station wagon has 4 wheels" << endl; }
		void getNumDoors(){ cout << "Station wagon has 4 doors" << endl; }
		StationWagon(){}
		~StationWagon(){}
};

int main() {
	// This works
	Animal* pCat = new Cat;
	Animal* pDog = new Dog;

	// This does not
	// Cat* p2Cat = new Animal;
	// That makes sense though. The resulting variable, p2Cat, is of type Cat.. but we
	// are trying to instantiate it with Animal's constructor.. Cat is presumed to
	// have variables and methods that the base class, Animal is unaware of..
	// How would we assign values to these things if we are using Animal's constructor
	// for instantiation??

	// or

	// can ALWAYS pass a derived class to something that is expecting the base class
	// because the derived class's variables will just get 'trimmed' off

	pCat->makeSound();
	pDog->makeSound();

	// just showing the same thing again.
	Car* stationWagon = new StationWagon();
	stationWagon->getNumWheels();

	return 0;
}