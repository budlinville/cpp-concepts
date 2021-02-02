#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// typedef old_type new_type
//		old_type = "struct Doggy"
//		new_type = "Dog"
typedef struct Doggy {
	string name;
	int age;
	struct Doggy* mother;
	// this is not valid because Dog hasn't been defined yet..
	// Dog* father;
} Dog;

// if i only need one
struct Cat {
	string name;
	int age;
} maximus;

// this works of course too
struct Mouse {
	string name;
	int age;
};

int main() {
	// both are valid
	struct Doggy peepers;
	Dog ollie;

	maximus.name = "Maximus";
	maximus.age = 14;

	struct Mouse stuartLittle;

	return 0;
}