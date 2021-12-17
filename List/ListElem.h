#pragma once
template <class T> class ListElem
{
	T content;
	ListElem* next;
public:
	ListElem(const T& add_content, ListElem* add_next);
	const T& GetData() const;
	ListElem<T>* GetNext();
	template <class T> friend class List;
};

template<class T>
inline ListElem<T>::ListElem(const T& add_content, ListElem* add_next)
{
	content = add_content;
	next = add_next;
}

template<class T>
inline const T& ListElem<T>::GetData() const
{
	return content;
}

template<class T>
inline ListElem<T>* ListElem<T>::GetNext()
{
	return next;
}