#pragma once
#include <iostream>

using namespace std;

class Rational
{
public:
	int numer, 
		denom;

	Rational();
	Rational(int a, int b);
	Rational(int number);
	
	void simplify();
	Rational& operator +=(const Rational& r);
	Rational operator +(const Rational& r) const;
	Rational operator -() const;
	Rational& operator -=(const Rational& r);
	Rational operator -(const Rational& r) const;
	Rational operator *(const Rational& r) const;
	Rational operator /(const Rational& r) const;
	bool operator >(const Rational& r) const;
	bool operator >=(const Rational& r) const;
	bool operator <(const Rational& r) const;
	bool operator <=(const Rational& r) const;
	bool operator ==(const Rational& r) const;
	Rational sq();

	friend std::istream& operator >>(std::istream& in, Rational& r);
	friend std::ostream& operator <<(std::ostream& out, const Rational& r);
};

