#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/**************************
 * Overloading/overwriting
 **************************/

class Mathy {
	public:
		// This is overwriting
		static void add(int x) { cout << x << endl; }
		static void add(int x, int y) { cout << x + y << endl; }
		static void add(int x, int y, int z) { cout << x + y + z << endl; }
		static void add(int x[], int size) {
			int sum = 0;
			for (int i = 0; i < size; i++) {
				sum += x[i];
			}
			cout << sum << endl;
		}
};

// This is overloading
class Dumb_Mathy : public Mathy {
	private:
		static int getRandom(int min, int max) { return(rand() % max) + min; }
	public:
		static void add(int x) { cout << getRandom(0, 10) << endl; }
		static void add(int x, int y) { cout << getRandom(0, 10) << endl; }
		static void add(int x, int y, int z) { cout << getRandom(0, 10) << endl; }
		static void add(int x[], int size) { cout << getRandom(0, 10) << endl; }
};

int main() {
	// note that to access static methods, we need the scope resolution operator
	// Mathy::add... not Mathy.add
	Mathy::add(1);
	Mathy::add(1, 2);
	Mathy::add(1, 2, 3);
	int arr[] = {1, 2, 3, 4, 5, 6};
	Mathy::add(arr, 6);

	Dumb_Mathy::add(1);

	return 0;
}