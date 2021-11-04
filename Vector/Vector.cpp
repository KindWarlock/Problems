#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
	Array vec;
	//инициализация вектора с превыщением capacity по умолчанию
	for (int i = 0; i <= 33; i++) {
		vec.insert(i);
		cout << vec[i] << ' ';
	}
	cout << endl;
	
	//удаление элемента
	vec.remove(30);
	for (int i = 0; i < vec.getSize(); i++) {
		cout << vec[i] << ' ';
	}
	cout << endl;

	//конструктор копирования
	Array vec_new(vec);
	vec_new.insert(vec_new.getSize());
	for (int i = 0; i < vec_new.getSize(); i++) {
		cout << vec_new[i] << ' ';
	}
	cout << endl;

	//копирование
	vec_new = vec;
	for (int i = 0; i < vec_new.getSize(); i++) {
		cout << vec_new[i] << ' ';
	}
	return 0;
}