// Before c++11, no concept of nullptr
#define nullptr 0

template<typename T>
struct Node {
	T value;
	Node* next;
	Node(T val) {
		value = val;
		next = nullptr;
	}
};