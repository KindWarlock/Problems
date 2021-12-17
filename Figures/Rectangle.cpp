#include "Figura.h"

Rectangle::Rectangle()
{
	a = 1.0;
	b = 1.0;
}

Rectangle::Rectangle(double a_new, double b_new)
{
	a = a_new;
	b = b_new;
}

double Rectangle::calc_area()
{
	return a * b;
}

double Rectangle::calc_perimetr()
{
	return 2 * (a + b);
}

char* Rectangle::get_name() {
	char* name = new char[10];
	strncpy_s(name, 10, "Rectangle", 10);
	return name;
}