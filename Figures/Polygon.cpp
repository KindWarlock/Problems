#include "Figura.h"

Polygon::Polygon()
{
	points = { {1.0, 1.0} };
}

Polygon::Polygon(std::vector<std::pair<double, double>>& points_new)
{
	points = points_new;
}

double Polygon::calc_area()
{
	double f = 0.0, s = 0.0;
	for (size_t i = 1; i < points.size(); i++) {
		f += points[i].second * points[i - 1].first;
	}
	f += points[0].second * points[points.size() - 1].first;

	for (size_t i = 1; i < points.size(); i++) {
		s += points[i].first * points[i - 1].second;
	}
	s += points[0].first * points[points.size() - 1].second;
	return (s - f) / 2;
}

double Polygon::calc_perimetr()
{
	double per = 0;
	double x, y;
	double length;
	for (int i = 0; i < points.size() - 1; i++) {
		x = points[i + 1].first - points[i].first;
		y = points[i + 1].second - points[i].second;
		length = sqrt(x * x + y * y);
		per += length;
	}
	x = points[0].first - points[points.size() - 1].first,
	y = points[0].second - points[points.size() - 1].second;
	length = sqrt(x * x + y * y);
	per += sqrt(x * x + y * y);
	return per;
}

char* Polygon::get_name() {
	char* name = new char[10];
	strncpy_s(name, 10, "Polygon", 10);
	return name;
}