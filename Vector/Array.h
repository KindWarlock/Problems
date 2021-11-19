#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

const int DEFAULT_SIZE = 32;
const int EXPAND_CAPACITY = 10;

class Array
{
	int *ptr;
	int size;
	int capacity;

public:
	explicit Array(int startSize=DEFAULT_SIZE);
	~Array();
	Array(const Array &arr);

	Array& operator= (const Array &arr);
	int& operator[] (int index);

	
	void expand(int diffCap=EXPAND_CAPACITY);
	void insert(int num);
	void insert(int num, int index);
	void insert(int* num, int arr_size);
	void insert(int* num, int arr_size, int index);
	
	int getSize();
	void remove(int index);
	friend std::ostream& operator <<(std::ostream& out, Array &vec);
};

