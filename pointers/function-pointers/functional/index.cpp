#include <functional>
#include <iostream>

using namespace std;

typedef std::function<bool(int)> intToBool;

int main() {

	intToBool greaterThanThree = [](int val){ return val > 3; };

	cout << greaterThanThree(4) << endl;

	return 0;
}