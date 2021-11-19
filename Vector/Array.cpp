#include "Array.h"

Array::Array(int startSize) {
	if (startSize <= 0)
		capacity = DEFAULT_SIZE;
	else
		capacity = startSize;
	ptr = new int[capacity];
	size = 0;
}

Array::Array(const Array& arr)
{
	ptr = new int[arr.capacity];
	size = arr.size;
	capacity = arr.capacity;
	for (int i = 0; i < size; i++) {
		ptr[i] = arr.ptr[i];
	}
}

Array::~Array()
{
	delete[] ptr;
}

Array& Array::operator= (const Array& arr) {
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

int& Array::operator[](int index)
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

void Array::expand(int diffCap)
{
	int* tmp = new int[capacity + diffCap];
	for (int i = 0; i < capacity; i++) {
		tmp[i] = ptr[i];
	}
	delete[] ptr;
	ptr = tmp;
	capacity += diffCap;
}

void Array::insert(int num, int index) {
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

void Array::insert(int num) {
	insert(num, size);
}

void Array::insert(int* num, int arr_size)
{
	for (int i = 0; i < arr_size; i++) {
		insert(num[i]);
	}
}

void Array::insert(int* num, int arr_size, int index)
{
	for (int i = 0; i < arr_size; i++) {
		insert(num[i], index + i);
	}
}

void Array::remove(int index)
{
	try {
		if (index > size || index < 0) {
			throw out_of_range("wrong index");
		}

		/* при i == size - 1 ничего плохого не произойдет,
		т.к доступа в ту €чейку не будет */
		for (int i = index; i < size; i++) {
			ptr[i] = ptr[i + 1];	
		}
		size--;
	}
	catch (out_of_range ex) {
		cout << ex.what() << endl;
	}
}


int Array::getSize()
{
	return size;
}

std::ostream& operator<<(std::ostream& out, Array& vec)
{
	for (int i = 0; i < vec.size; i++) {
		out << vec[i] << ' ';
	}
	out << endl;
	return out;
}
