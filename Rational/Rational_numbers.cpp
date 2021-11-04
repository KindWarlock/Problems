#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{
    int a1, a2,
        b1, b2;
    
    cout << "Enter numerator a, denumerator a, numerator b, denumerator b\n";
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
    return 0;
}