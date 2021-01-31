#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// toggle this to either run production or debug code
#define DEBUG
// also makes sense in the context of including different code based on
// the environment being run in, as seen at Garmin

#define PI 3.14159
#define CIRCUMFERENCE(r) 2 * PI * r
#define AREA(r) PI * r * r

using namespace std;

int main() {
	const int radius = (int)5.69;
	cout << "Circumference: " << CIRCUMFERENCE(radius) << endl;
	cout << "Area: " << AREA(radius) << endl;
	#ifdef DEBUG
		cout << "The original radius was " << radius << endl;
	#endif
	return 0;
}