#include <iostream>
using namespace std;

void to_bits(int num) {
    for (int i = 15; i >= 0; i--)
        cout << ((num >> i) & 1);
    cout << endl;
}

void to_byte(int& num) {
    //  контр. биты будут располагаться на поз. 4, 2, 1 
    bool zero_bit = (num & 1);
    num = num << 4;
    num = num & 0b11100000;
    num += (zero_bit << 3);
}

void contr_sums(int& num) {
    to_byte(num);
    bool cs1, cs2, cs3;
    bool bits[8];
    for (int i = 0; i < 8; i++)
        bits[i] = (num >> i) & 1;
    cs1 = bits[3] ^ bits[5] ^ bits[7];
    cs2 = bits[3] ^ bits[6] ^ bits[7];
    cs3 = bits[5] ^ bits[6] ^ bits[7];
    num |= (cs1 << 1) | (cs2 << 2) | (cs3 << 4);
}


int main()
{
    int num, num1, num2;
    cin >> num;
    num1 = num >> 4;
    num2 = num ^ (num1 << 8);
    contr_sums(num1);
    contr_sums(num2);
    int coded_num = (num1 << 8) | num2;
    cout << "Decimal: " << coded_num << endl;
    cout << "Binary: ";
    to_bits(coded_num);
    return 0;
}

