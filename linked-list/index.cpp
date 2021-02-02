#include "linked-list.cpp"

int main() {
	LinkedList<int>* list = new LinkedList<int>();

	list->add(5);
	list->add(7);
	list->add(8);

	list->printList();

	return 0;
}