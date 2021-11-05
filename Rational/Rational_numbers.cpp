#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{
    int a1, a2,
        b1, b2;
    
    cout << "Enter numerator a, denomerator a, numerator b, denomerator b\n";
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

    cout << "Sqrt a: " << a.sqrt() << endl;
    cout << "Sqrt b: " << b.sqrt() << endl;
    return 0;
}