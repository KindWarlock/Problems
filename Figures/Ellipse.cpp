#include "Figura.h"

Ellipse::Ellipse()
{
	r = 1.0;
	r_big = 1.0;
}

Ellipse::Ellipse(double r_big_new, double r_new)
{
	r = r_new;
	r_big = r_big_new;
}

double Ellipse::calc_area()
{
	return PI * r * r_big;
}

double Ellipse::calc_perimetr()
{
	return 2 * PI * sqrt((r * r + r_big * r_big) / 2);
}

char* Ellipse::get_name() {
	char* name = new char[10];
	strncpy_s(name, 10, "Ellipse", 10);
	return name;
}