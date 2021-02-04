#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

	vector<int> values = {1, 2, 3, 4, 5};

	for (vector<int>::iterator it = values.begin(); it != values.end(); it++) {
		cout << *it << endl;
	}

	/* Could just do:
	 *	for (val : values) { ... }
	 * But this is only effective in ordered data types (like vector or array)
	 * where traversing is easy (and linear)
	 */

	typedef unordered_map<string, int> ScoreMap;
	//using ScoreMap = unordered_map<string, int>;	// this works too

	// using strings as keys (or indexes), not ints..
	// how to traverse this?
	ScoreMap map;
	map["cherno"] = 5;
	map["C++"] = 2;

	for (ScoreMap::const_iterator it = map.begin();
		it != map.end(); it++) {
		auto& key = it->first;
		auto& value = it->second;

		cout << key << " = " << value << endl;
	}

	cout << "--------" << endl;
	
	// can iterate with range-based for loop actually
	for (auto kv : map) {
		auto& key = kv.first;
		auto& value = kv.second;

		cout << key << " = " << value << endl;
	}

	cout << "--------" << endl;

	// with C++ 17
	for (auto [key, value] : map) {
		cout << key << " = " << value << endl;
	}

	return 0;
}