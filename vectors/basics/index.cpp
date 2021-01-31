#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/* 
 * How do vectors resize?
 * Creates new vector twice the length of old one, copies old values over
 * 
 * When passing to a function, do try to use references, so you're creating
 * an entire copy of the vector
 */

using namespace std;

// standard way to iterate over any linear data type
template <typename T>
void print1(vector<T>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];	// equivalent to vec.at(i);
		if (i != vec.size() - 1) cout << ", ";
	}
	cout << endl;
}

// C++11 way of iterating through a vector
template <typename T>
void print2(vector<T>& vec) {
	// use & to avoid copying each element into scope of for-loop
	for (T& v : vec) {
		cout << v << ", ";
		// no way to tell if at last element
	}
	cout << endl;
}

// Pre-C++11 way of iterating through a vector
template <typename T>
void print3(vector<T>& vec) {
	for (typename vector<T>::iterator it = vec.begin(); it != vec.end(); ++it) {
		cout << *it;
		if (it +1 != vec.end()) cout << ", ";
	}
	cout << endl;
}

// Pre-C++11 way of iterating through a vector, but using indices
template <typename T>
void print4(vector<T>& vec) {
	for (typename vector<T>::size_type i = 0; i != vec.size(); i++) {
		cout << vec[i];
		if (i != vec.size() - 1) cout << ", ";
	}
	cout << endl;
}

int main() {
	vector<int> nums;
	nums.push_back(33);
	nums.push_back(44);
	nums.push_back(33);
	nums.push_back(12);
	nums.push_back(88);
	nums.push_back(91);
	nums.push_back(62);
	nums.push_back(87);

	print1(nums);
	print2(nums);
	print3(nums);
	print4(nums);

	//erase the fifth element
	nums.erase(nums.begin() + 4);
	print1(nums);

	return 0;
}