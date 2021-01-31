#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int add(int num1, int num2 = 0) {
	int combinedValue = num1 + num2;
	return combinedValue;
}

int add(int num1, int num2, int num3) {
	int combinedValue = num1 + num2 + num3;
	return combinedValue;
}

int getFactorial(int num) {
	int sum;
	if (num == 1) {
		return 1;
	}
	return num * getFactorial(num - 1);
}

int main() {
	cout << add(1) << endl;

	cout << add(1, 5, 6) << endl;

	cout << getFactorial(6) << endl;

	return 0;
}