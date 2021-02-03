#include <iostream>
#include <string>
#include <memory>	// need this for smart pointers

using namespace std;

class Entity {
	public:
		Entity() { cout << "Created entity!" << endl; }
		~Entity() { cout << "Destroyed entity!" << endl; }
		void print() { cout << "print" << endl; }
};

int main() {
	// unique_ptr gets deleted when it goes out of scope
	{
		// can't do : unique_ptr<Entity> entity = new Entity();
		// one way:
		unique_ptr<Entity> ent1(new Entity());
		// better way - prevents memory leak from dangling pointer if exception is thrown
		// this is only available with c++14 and up though
		unique_ptr<Entity> ent2 = make_unique<Entity>();
		ent2->print();

		// cannot delete a unique_ptr... b/c its unique.. ik shocker
		//unique_ptr<Entity> ent3 = ent2;	// wont work
	}

	cout << "------------------------------" << endl;

	// shared_ptr usually implemented through "reference count".. wrapper data structure
	// keeps track of nummber of references. When that count hits 0, instance is deleted

	// with shared_ptr, definitely do not want to instantiate like this:
	// shared_ptr<Entity> entity(new Entity());
	// this would require two memory allocations. one for the Entity, one for Reference counter
	// calling it the other way combines those steps
	shared_ptr<Entity> e0 = make_shared<Entity>();
	{
		shared_ptr<Entity> e1 = e0;
	}

	// use this to pause program. Note that destructor has not been called
	// b/c e0 still in scope
	string arbitrary;
	cin >> arbitrary;

	cout << "------------------------------" << endl;

	// also weak_ptrs which are like shared_ptrs but they don't increase ref count
	shared_ptr<Entity> sharedPtr = make_shared<Entity>();
	shared_ptr<Entity> sharedPtr2 = sharedPtr;
	weak_ptr<Entity> weakPtr = sharedPtr;

	// 2 not 3
	cout << "Number of references: " << sharedPtr.use_count() << endl;
	return 0;
}