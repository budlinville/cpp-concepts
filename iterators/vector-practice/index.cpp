#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

template<typename T>
class VectorWrapper {
	private:
		vector<T> vec;
	public:
		VectorWrapper() {}
		VectorWrapper(T arr[], int size) {
			for (int i = 0; i < size; i++) {
				vec.push_back(arr[i]);
			}
		}
		void printVector() {
			for (T item : vec) {
				cout << item << endl;
			}
		}
		void addAtPos(int pos, T val) {
			if (pos < 0 || pos >= vec.size()) {
				return;
			} else if (pos == vec.size() - 1) {
				vec.push_back(val);
				return;
			}
			vector<T> newVec;
			for (typename vector<T>::iterator it = vec.begin(); it != vec.end(); it++)
			{
				if (it - vec.begin() == pos) {
					newVec.push_back(val);
				} 
				newVec.push_back(*it);
			}
			vec = newVec;
		}

		void removeFromPos(int pos) {
			if (pos < 0 || pos >= vec.size()) {
				return;
			}
			vector<T> newVec;
			for (typename vector<T>::iterator it = vec.begin(); it != vec.end(); it++) {
				if (it - vec.begin() != pos) {
					newVec.push_back(*it);
				}
			}
			vec = newVec;
		}
};

int main() {
	int size = 4;
	int arr[] = {1, 3, 5, 6};
	VectorWrapper<int> vw(arr, size);
	vw.printVector();

	cout << "---------" << endl;

	vw.addAtPos(3, 9);
	vw.printVector();

	cout << "---------" << endl;

	vw.removeFromPos(3);
	vw.printVector();

	return 0;
}