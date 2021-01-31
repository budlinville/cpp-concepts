#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Foo {
	public:
		virtual void toString() { cout << "Foo" << endl; }
};

class Bar : public Foo {
	private:
		string name;
	public:
		Bar() { this->name = "Bar"; }
		Bar(string n) { this->name = n; }
		void toString() override { cout << "Bar" << endl; }
		void getName() { cout << "Name: " << name << endl; }
};

// 1. Pass derived type to this
// 2. Treated as Base class
// 3. Convert back to derived class
Bar* reinterpret(Foo* foo) {
	cout << "--- As Foo ---" << endl;
	foo->toString();
	return reinterpret_cast<Bar*>(foo);
}

int main() {
	cout << "--- Original Bar ---" << endl;
	Bar* bar = new Bar("Barry");
	bar->toString();
	bar->getName();

	Bar* reinterprettedBar = reinterpret(bar);

	cout << "--- Reinterpreted Bar ---" << endl;
	reinterprettedBar->toString();
	reinterprettedBar->getName();

	return 0;
}