#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

const int DEFAULT_SIZE = 32;
const int EXPAND_CAPACITY = 10;

template <class T> class Vector
{
	T* ptr;
	int size;
	int capacity;

public:
	explicit Vector<T>(int startSize = DEFAULT_SIZE);
	~Vector<T>();
	Vector<T>(const Vector<T>& arr);

	Vector<T>& operator= (const Vector<T>& arr);
	T& operator[] (int index);


	void expand(int diffCap = EXPAND_CAPACITY);
	void insert(T num);
	void insert(T num, int index);
	void insert(T* num, int arr_size);
	void insert(T* num, int arr_size, int index);

	int getSize();
	void remove(int index);
	template <class T1> friend std::ostream& operator <<(std::ostream& out, Vector<T1>& vec);
};

template<class T>
inline Vector<T>::Vector(int startSize) {
	if (startSize <= 0)
		capacity = DEFAULT_SIZE;
	else
		capacity = startSize;
	ptr = new T[capacity];
	size = 0;
}

template<class T>
inline Vector<T>::Vector(const Vector& arr)
{
	ptr = new T[arr.capacity];
	size = arr.size;
	capacity = arr.capacity;
	for (int i = 0; i < size; i++) {
		ptr[i] = arr.ptr[i];
	}
}

template<class T>
inline Vector<T>::~Vector()
{
	delete[] ptr;
}

template<class T>
inline Vector<T>& Vector<T>::operator= (const Vector<T>& arr) {
	if (size < arr.size) {
		delete[] ptr;
		if (capacity < arr.capacity) {
			capacity = arr.capacity;
		}
		ptr = new T[capacity];
	}
	size = arr.size;
	for (int i = 0; i < size; i++) {
		ptr[i] = arr.ptr[i];
	}
	return(*this);
}

template<class T>
inline T& Vector<T>::operator[](int index)
{
	try {
		if (index >= size || index < 0) {
			throw out_of_range("wrong index");
		}
		return ptr[index];
	}
	catch (out_of_range ex) {
		cout << ex.what() << endl;
	}
}

template<class T>
inline void Vector<T>::expand(int diffCap)
{
	T* tmp = new T[capacity + diffCap];
	for (int i = 0; i < capacity; i++) {
		tmp[i] = ptr[i];
	}
	delete[] ptr;
	ptr = tmp;
	capacity += diffCap;
}

template<class T>
inline void Vector<T>::insert(T num, int index) {
	try {
		if (index > size || index < 0) {
			throw out_of_range("wrong index");
		}

		if (size == capacity)
			expand();
		if (index != size)
			for (int i = size; i > index; i--) {
				ptr[i] = ptr[i - 1];
			}
		ptr[index] = num;
		size++;
	}
	catch (out_of_range ex) {
		cout << ex.what() << endl;
	}
}

template<class T>
inline void Vector<T>::insert(T num) {
	insert(num, size);
}

template<class T>
inline void Vector<T>::insert(T* num, int arr_size)
{
	for (int i = 0; i < arr_size; i++) {
		insert(num[i]);
	}
}

template<class T>
inline void Vector<T>::insert(T* num, int arr_size, int index)
{
	for (int i = 0; i < arr_size; i++) {
		insert(num[i], index + i);
	}
}

template<class T>
inline void Vector<T>::remove(int index)
{
	try {
		if (index > size || index < 0) {
			throw out_of_range("wrong index");
		}
		for (int i = index; i < size; i++) {
			ptr[i] = ptr[i + 1];
		}
		size--;
	}
	catch (out_of_range ex) {
		cout << ex.what() << endl;
	}
}


template<class T>
inline int Vector<T>::getSize()
{
	return size;
}

template <class T1>
std::ostream& operator<<(std::ostream& out, Vector<T1>& vec)
{
	for (int i = 0; i < vec.getSize(); i++) {
		out << vec[i] << ' ';
	}
	out << endl;
	return out;
}