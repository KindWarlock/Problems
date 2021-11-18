#pragma once
#include "ListElem.h"
#include <iostream>

template <class T> class List
{
	ListElem<T>* start;
public:
	List();
	List(const List& list);
	List& operator=(const List& list);
	~List();
	ListElem<T>* getStart();
	void deleteFirst();
	void deleteAfter(ListElem<T>* ptr);
	void insertFirst(const T& data);
	ListElem<T>* insertAfter(ListElem<T>* ptr, const T& data);
	template <class T> friend std::ostream& operator <<(std::ostream& out, List<T>& list);
};

template<class T>
inline List<T>::List()
{
	start = 0;
}

template<class T>
inline List<T>::List(const List& list)
{
	insertFirst(list->start->content);
	ListElem<T>* ptr_next = list->start->next;
	ListElem<T>* ptr = start;
	while (ptr) {
		insertAfter(ptr, ptr_next->content);
		ptr_next = ptr_next->next;
		ptr = ptr->next;
	}
}

template<class T>
inline List<T>::~List()
{
	while (start)
		deleteFirst();
}

template<class T>
inline ListElem<T>* List<T>::getStart()
{
	return start;
}

template<class T>
inline void List<T>::deleteFirst()
{
	ListElem<T>* tmp = start->next;
	delete(start);
	start = tmp;
}

template<class T>
inline void List<T>::deleteAfter(ListElem<T>* ptr)
{
	ListElem<T>* tmp = ptr->next->next;
	delete(ptr->next);
	ptr->next = tmp;
}

template<class T>
inline void List<T>::insertFirst(const T& data)
{
	ListElem<T>* new_elem = new ListElem<T>(data, start);
	start = new_elem;
}

template<class T>
inline ListElem<T>* List<T>::insertAfter(ListElem<T>* ptr, const T& data)
{
	ListElem<T>* new_elem = new ListElem<T>(data, ptr->next);
	ptr->next = new_elem;
	return new_elem;
}

template<class T>
inline std::ostream& operator<<(std::ostream& out, List<T>& list)
{
	ListElem<T>* ptr = list.start;
	while (ptr) {
		out << ptr->GetData() << ' ';
		ptr = ptr->GetNext();
	}
	return out;
}
