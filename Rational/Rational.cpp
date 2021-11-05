#include "Rational.h"

using namespace std;

//Конструкторы
Rational::Rational() {
	numer = 0;
	denom = 1;
}

Rational::Rational(int a, int b) {
	numer = a;
	denom = b;
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
	/* итерационная формула Герона
	 Rational prev(*this);
	for (int i = 1; i < 6; i++) {
		prev = Rational(1, 2) * (prev + *this / prev);
		prev.simplify();
	}
	return prev;
	*/
	double sq = sqrt((double)numer/denom);
	int n_mod = 1;
	while (!trunc(sq) == sq) {
		sq /= 10;
		n_mod *= 10;
	}
	Rational sqed(sq, n_mod);
	sqed.simplify();
	return sqed;
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

std::ostream& operator <<(std::ostream& out, Rational& r) {
	out << r.numer << '/' << r.denom;
	return out;
}