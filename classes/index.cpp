#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Animal{
	private:
		int height;
		int weight;
		string name;

		static int numOfAnimals;

	public:
		int getHeight() { return height; }
		int getWeight() { return weight; }
		string getName() { return name; }
		// Motivation behind this ENCAPSULATION
		// Can protect our variable by adding checks for only 'reasonable' values
		void setHeight(int cm) { height = cm; }
		void setWeight(int kg) { weight = kg; }
		void setName(string animalName) { name = animalName; }

		// Below are prototypes
		void setAll(int, int, string);

		Animal(int, int, string);
		// overloading constructor
		Animal();

		~Animal();

		static int getNumOfAnimals() { return numOfAnimals; }

		void toString();
};

int Animal::numOfAnimals = 0;

void Animal::setAll(int height, int weight, string name){
	this->height = height;
	this->weight = weight;
	this->name = name;
}

Animal::Animal(){ Animal::numOfAnimals++; }

Animal::Animal(int height, int weight, string name){
	this->height = height;
	this->weight = weight;
	this->name = name;
	Animal::numOfAnimals++;
}

Animal::~Animal(){
	cout << "Animal " << this->name << " destroyed!" << endl;
}

void Animal::toString(){
	cout << this->name << " is " << this->height << " cms tall and "
		<< this->weight << " kgs in weight." << endl;
}

class Dog : public Animal{
	private: 
		string sound = "Woof";

	public:
		Dog() : Animal(){};
		Dog(int, int, string);
		Dog(int, int, string, string);

		// would prefer for these to return values but oh well
		void getSound(){ cout << "Woof" << endl; }
		void toString();
};

Dog::Dog(int height, int weight, string name, string bark) : Animal(height, weight, name) {
	this->sound = bark;
}
Dog::Dog(int height, int weight, string name) : Animal(height, weight, name) {}

void Dog::toString(){
	// could have (and probably should have) made name, weight, and height protected
	// variables so we don't have to use the public getters below
	cout << this->getName() << " is " << this->getHeight() << " cms tall and "
		<< this->getWeight() << " kgs in weight and says " 
		<< this->sound << endl;
}

int main() {
	Animal fred;
	fred.setHeight(33);
	fred.setWeight(10);
	fred.setName("Fred");
	cout << fred.getName() << " is " << fred.getHeight() << " cms tall and "
		<< fred.getWeight() << " kgs in weight." << endl;

	Animal tom(36, 15, "Tom");
	cout << tom.getName() << " is " << tom.getHeight() << " cms tall and "
		<< tom.getWeight() << " kgs in weight." << endl;

	Dog spot(38, 16, "Spot", "Bark");

	Dog ollie(45, 12, "Ollie");

	cout << "Number of Animals " << Animal::getNumOfAnimals() << endl;
	spot.getSound();
	ollie.getSound();

	tom.toString();
	spot.toString();
	ollie.toString();

	// NOTE : didn't know this before, but you can always call the superclass method
	// by making use of the 'scope operator'..
	spot.Animal::toString();

	return 0;
}