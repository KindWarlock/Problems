#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

const int DEFAULT_SIZE = 32;
const int EXPAND_CAPACITY = 10;

template <class T> class Vector
{
	int *ptr;
	int size;
	int capacity;

public:
	explicit Vector(int startSize=DEFAULT_SIZE);
	~Vector();
	Vector(const Vector &arr);

	Vector& operator= (const Vector &arr);
	int& operator[] (int index);

	
	void expand(int diffCap=EXPAND_CAPACITY);
	void insert(int num);
	void insert(int num, int index);
	void insert(int* num, int arr_size);
	void insert(int* num, int arr_size, int index);
	
	int getSize();
	void remove(int index);
	friend std::ostream& operator <<(std::ostream& out, Vector &vec);
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
	ptr = new int[arr.capacity];
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
inline Vector& Vector<T>::operator= (const Vector& arr) {
	if (size < arr.size) {
		delete[] ptr;
		if (capacity < arr.capacity) {
			capacity = arr.capacity;
		}
		ptr = new int[capacity];
	}
	size = arr.size;
	for (int i = 0; i < size; i++) {
		ptr[i] = arr.ptr[i];
	}
	return(*this);
}

template<class T> 
inline int& Vector<T>::operator[](int index)
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
	int* tmp = new int[capacity + diffCap];
	for (int i = 0; i < capacity; i++) {
		tmp[i] = ptr[i];
	}
	delete[] ptr;
	ptr = tmp;
	capacity += diffCap;
}

template<class T> 
inline void Vector<T>::insert(int num, int index) {
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
inline void Vector<T>::insert(int num) {
	insert(num, size);
}

template<class T> 
inline void Vector<T>::insert(int* num, int arr_size)
{
	for (int i = 0; i < arr_size; i++) {
		insert(num[i]);
	}
}

template<class T>
inline void Vector<T>::insert(int* num, int arr_size, int index)
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

std::ostream& operator<<(std::ostream& out, Vector& vec)
{
	for (int i = 0; i < vec.size; i++) {
		out << vec[i] << ' ';
	}
	out << endl;
	return out;
}