#pragma once
template <class T> class ListElem
{
	T content;
	ListElem* next;
public:
	ListElem(T add_content, ListElem* add_next);
	const T& GetData() const;
	ListElem* GetNext();
	template <class T> frient class List;
};

