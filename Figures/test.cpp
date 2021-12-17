#include "Figura.h"
#include <string>
#include <map>

const int ELLIPSE = 4;
const int RECTANGLE = 1;
const int TRIANGLE = 2;
const int POLYGON = 3;

void createMap(std::map<std::string, int>& mapping) {
	mapping["ellipse"] = ELLIPSE;
	mapping["rectangle"] = RECTANGLE;
	mapping["triangle"] = TRIANGLE;
	mapping["polygon"] = POLYGON;
}

void coutCalcs(Figura& figure) {
	std::cout << "\nName: " << figure.get_name() << '\n';
	std::cout << "Area: "  << figure.calc_area() << '\n';
	std::cout << "Perimetr: " << figure.calc_perimetr() << '\n';
}

void readFigure(std::string name, std::vector<Figura*>& figs, std::map<std::string, int>& names_mapping) {
	switch (names_mapping[name]) {
	case ELLIPSE:
	{
		double r, r_big;
		std::cout << "Enter r and R: ";
		std::cin >> r >> r_big;
		Ellipse* fig = new Ellipse(r_big, r);
		figs.push_back(fig);
	}
	break;
	case RECTANGLE:
	{
		double a_rec, b_rec;
		std::cout << "Enter a and b: ";
		std::cin >> a_rec >> b_rec;
		Rectangle* fig = new Rectangle(a_rec, b_rec);
		figs.push_back(fig);
	}
	break;
	case TRIANGLE:
	{
		double a_tr, b_tr, c_tr;
		std::cout << "Enter a, b and c: ";
		std::cin >> a_tr >> b_tr >> c_tr;
		Triangle* fig = new Triangle(a_tr, b_tr, c_tr);
		figs.push_back(fig);
	}
	break;
	case POLYGON:
	{
		std::vector<std::pair<double, double>> points;
		std::pair<double, double> coords;
		std::cout << "Enter points clockwise, to stop enter ';': ";
		while (1) {
			char inp = ' ';
			std::cin >> inp;
			if (inp == ';') {
				break;
			}
			if (inp == '-') {
				std::cin >> inp;
				coords.first = -(inp - '0');
			}
			else
				coords.first = inp - '0';
			std::cin >> coords.second;
			points.push_back(coords);
		}
		Polygon* fig = new Polygon(points);
		figs.push_back(fig);
	}
	}
}

int main() {
	std::map<std::string, int> names_mapping;
	createMap(names_mapping);
	std::vector<Figura*> figs;
	std::cout << "Enter ';' to stop.\n";
	while (1) {
		std::string name;
		std::cout << "Enter figure name in lowercase: ";
		std::cin >> name;
		if (name == ";") {
			break;
		}
		if (names_mapping[name] == 0) {
			std::cout << "No such figure!\n";
			continue;
		}
		readFigure(name, figs, names_mapping);
	}
	for (int i = 0; i < figs.size(); i++) {
		coutCalcs(*figs[i]);
		delete figs[i];
	}
	return 0;
}