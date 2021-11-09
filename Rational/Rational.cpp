#include "Rational.h"

//Конструкторы
Rational::Rational() {
	numer = 0;
	denom = 1;
}

Rational::Rational(int a, int b) {
	numer = a;
	denom = b;
	if (b == 0) {
		throw std::domain_error("division by 0");
	}
}

Rational::Rational(int number) {
	numer = number;
	denom = 1;
}

//Арифметические операторы
void Rational::simplify() {
	int a = abs(denom), b = abs(numer);
	if ((a == 0) || (b == 0))
		return;
	while (a != b) {
		
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	denom /= b;
	numer /= b;
}

Rational& Rational::operator +=(const Rational& r) {
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}

Rational Rational::operator +(const Rational& r) const{
	Rational res(*this);
	res += r;
	return res;
}

Rational Rational::operator -() const{
	Rational r(-numer, denom);
	return r;
}

Rational& Rational::operator -=(const Rational& r) {
	return *this += (-r);
}

Rational Rational::operator -(const Rational& r) const {
	Rational res(*this);
	res -= r;
	return res;
}

Rational Rational::operator *(const Rational& r) const {
	Rational res(*this);
	res.numer *= r.numer;
	res.denom *= r.denom;
	res.simplify();
	return res;
}

Rational Rational::operator /(const Rational& r) const {
	Rational res(*this);
	res.denom *= r.numer;
	res.numer *= r.denom;
	res.simplify();
	return res;
}

Rational Rational::sq() {
	/* 
	итерационная формула Герона
	 Rational prev(*this);
	for (int i = 1; i < 6; i++) {
		prev = Rational(1, 2) * (prev + *this / prev);
		prev.simplify();
	}
	return prev;
	*/
	double sq = sqrt((double)numer/denom);
	int n_mod = 1;

	//add intmax check
	for (int i = 0; i < 5; i++) {
		if (trunc(sq) == sq)
			break;
		sq *= 10;
		n_mod *= 10;
	}
	Rational sqed(sq, n_mod);
	sqed.simplify();
	return sqed;
}

std::pair<Rational, Rational> Rational::DecideEquation(const Rational& a, const Rational& b, const Rational& c)
{
	Rational D = b * b - Rational(4) * a * c;
	Rational x1 = (-b + D.sq()) / (a + a);
	Rational x2 = (-b - D.sq()) / (a + a);
	std::pair<Rational, Rational> x = std::make_pair(x1, x2);
	return x;
}

bool Rational::operator >(const Rational& r) const {
	Rational t = *this - r;
	if (t.numer > 0)
		return true;
	else
		return false;
}

bool Rational::operator >=(const Rational& r) const {
	Rational t = *this - r;
	if (t.numer >= 0)
		return true;
	else
		return false;
}

bool Rational::operator <(const Rational& r) const {
	Rational t = *this - r;
	if (t.numer < 0)
		return true;
	else
		return false;
}

bool Rational::operator <=(const Rational& r) const {
	Rational t = *this - r;
	if (t.numer <= 0)
		return true;
	else
		return false;
}

bool Rational::operator ==(const Rational& r) const {
	Rational t = *this - r;
	if (t.numer == 0)
		return true;
	else
		return false;
}

//Ввод-вывод

std::istream& operator >>(std::istream& in, Rational& r) {
	in >> r.numer >> r.denom;
	return in;
}

std::ostream& operator <<(std::ostream& out, const Rational& r) {
	out << r.numer << '/' << r.denom;
	return out;
}