#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
	Array vec;
	//инициализация вектора с превыщением capacity по умолчанию
	for (int i = 0; i <= 33; i++) {
		vec.insert(i);
	}
	cout << vec;

	int i[3] = { 100, 101, 102 };
	vec.insert(i, 3, 30);
	cout << vec;
	
	//удаление элемента
	vec.remove(30);
	cout << vec;

	//конструктор копирования
	Array vec_new(vec);
	vec_new.insert(vec_new.getSize());
	cout << vec;

	//копирование
	vec_new = vec;
	cout << vec;
	return 0;
}