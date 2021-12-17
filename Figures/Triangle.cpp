#include "Figura.h"

Triangle::Triangle()
{
	a = 1.0;
	b = 1.0;
	c = 1.0;
}

Triangle::Triangle(double a_new, double b_new, double c_new)
{
	a = a_new;
	b = b_new;
	c = c_new;
}

double Triangle::calc_area()
{
	double p = calc_perimetr() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::calc_perimetr()
{
	return a + b + c;
}

char* Triangle::get_name() {
	char* name = new char[10];
	strncpy_s(name, 10, "Triangle", 10);
	return name;
}