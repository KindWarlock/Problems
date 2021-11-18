#include "List.h"

int main() {
	List<int> int_list;
	int_list.insertFirst(0);
	ListElem<int>* ptr = int_list.getStart();
	for (int i = 1; i < 5; i++) {
		ptr = int_list.insertAfter(ptr, i);
	}
	int_list.deleteFirst();
	int_list.deleteAfter(int_list.getStart());
	std::cout << int_list;
	return 0;
}
