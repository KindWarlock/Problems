#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{
    int a1, a2,
        b1, b2,
        c1, c2;
    
    cout << "Enter numerator a, denomerator a, numerator b, denomerator b, numerator c, denomerator c\n";
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    
    try {
        Rational a(a1, a2), b(b1, b2), c(c1, c2);
    }
    catch (domain_error e) {
        cout << "ERROR: " << e.what();
        return -1;
    }
    Rational a(a1, a2), b(b1, b2), c(c1, c2);
    try {
        auto [x1, x2] = Rational::DecideEquation(a, b, c);
        cout << "x1: " << x1 << "\nx2: " << x2;
    }
    catch (range_error e) {
        cout << "ERROR: " << e.what();
        return -1;
    }
    /*
    cin >> a1 >> a2 >> b1 >> b2;
    Rational a(a1, a2), b(b1, b2);

    cout << "+: " << a + b << endl;
    cout << "-: " << a - b << endl;
    cout << "*: " << a * b << endl;
    cout << "/: " << a / b << endl;

    if (a > b)
        cout << a << " > " << b << endl;
    else if (a < b)
        cout << a << " < " << b << endl;
    else 
        cout << a << " = " << b << endl;

    cout << "Sqrt a: " << a.sq() << endl;
    cout << "Sqrt b: " << b.sq() << endl;
    */
    return 0;
}