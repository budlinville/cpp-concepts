#include <iostream>

#include "node.cpp"

using namespace std;

template<typename T>
class LinkedList {
	private:
		Node<T>* head;

	public:
		LinkedList() {
			head = nullptr;
		}

		LinkedList(Node<T>* node) {
			head = node;
		}

		~LinkedList() {
			Node<T>* cur = head;
			while (cur != nullptr) {
				Node<T>* next = head->next;
				delete cur;
				cur = next;
			}
		}

		void add(T val) {
			Node<T>* node = new Node<T>(val);
			if (head == nullptr) {
				head = node;
				return;
			}
			Node<T>* cur = head;
			Node<T>* next = head->next;
			while (next != nullptr) {
				cur = next;
				next = next->next;
			}
			cur->next = node;
		}

		void printList() {
			Node<T>* cur = head;
			while (cur != nullptr) {
				cout << cur->value;
				if (cur->next != nullptr) cout << ", ";
				cur = cur->next;
			}
			cout << endl;
		}

};