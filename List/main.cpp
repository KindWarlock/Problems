#include "List.h"

int main() {
	/*List<int> int_list;
	int_list.insertFirst(0);
	ListElem<int>* ptr = int_list.getStart();
	for (int i = 1; i < 5; i++) {
		ptr = int_list.insertAfter(ptr, i);
	}
	int_list.deleteFirst();
	int_list.deleteAfter(int_list.getStart());
	std::cout << int_list;*/
	int people_num, killing_order;
	std::cout << "Enter number of people: ";
	std::cin >> people_num;
	std::cout << "Enter person count dying: ";
	std::cin >> killing_order;

	List<int> alive_people;
	alive_people.insertFirst(1);
	ListElem<int>* elem_ptr = alive_people.getStart();
	for (int i = 2; i < people_num; i++) {
		elem_ptr = alive_people.insertAfter(elem_ptr, i);
	}
	alive_people.deleteFirst();
	elem_ptr = alive_people.insertAfter(elem_ptr, true, alive_people.getStart());
	for (int i = people_num - 1; i > 1; i--) {
		for (int k = 0; k < killing_order - 1; k++) {
			elem_ptr = elem_ptr->GetNext();
		}
		alive_people.deleteAfter(elem_ptr);
	}
	std::cout << alive_people.getStart()->GetData();
	return 0;
}
