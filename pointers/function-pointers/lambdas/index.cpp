#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// note that there is a C way of writing function pointers, but they are hard to read and rarely used anymore

// using a function as a type is weird, but here's the basic format:
// type_returned(*local_function_name)(types, passed, in)
void runFuncOnVec(vector<int>& nums, void(*func)(int)) {
	for (int num : nums) {
		func(num);
	}
}

int main() {
	string pre = "Value: ";

	// pass values into lambda via []
	// [](params)->return-type {}
	// no return-type needed below though
	auto lambda1 = [&pre](int val){ cout << pre << val << endl; };
	lambda1(26);

	cout << "-------------------" << endl;

	vector<int> myVector;
	myVector.push_back(3);
	myVector.push_back(11);
	myVector.push_back(29);
	myVector.push_back(54);
	myVector.push_back(88);

	// can only convert lambda to function pointer if it does not capture
	// i.e. does not have anything inside []
	auto lambda2 = [](int val){ cout << "Value: " << val << endl; };
	runFuncOnVec(myVector, lambda2);

	return 0;
}