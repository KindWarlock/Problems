#pragma once
#include <iostream>
#include <vector>

const double PI = atan(1) * 4;

class Figura
{
public:
	virtual double calc_area() = 0;
	virtual double calc_perimetr() = 0;
	virtual char* get_name() = 0;
};

class Rectangle : public Figura {
	double a, b;
public:
	Rectangle();
	Rectangle(double a_new, double b_new);

	virtual double calc_area();
	virtual double calc_perimetr();
	virtual char* get_name();
};

class Ellipse : public Figura {
	double r_big, r;
public:
	Ellipse();
	Ellipse(double r_big_new, double r_new);

	virtual double calc_area();
	virtual double calc_perimetr();
	virtual char* get_name();
};

class Triangle : public Figura {
	double a, b, c;
public:
	Triangle();
	Triangle(double a_new, double b_new, double c_new);

	virtual double calc_area();
	virtual double calc_perimetr();
	virtual char* get_name();
};

class Polygon : public Figura {
	std::vector<std::pair<double, double>> points;
public:
	Polygon();
	Polygon(std::vector<std::pair<double, double>>& points_new);

	virtual double calc_area();
	virtual double calc_perimetr();
	virtual char* get_name();
};
