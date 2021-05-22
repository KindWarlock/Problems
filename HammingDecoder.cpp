#include <iostream>
using namespace std;

void to_bits(int num) {
    for (int i = 15; i >= 0; i--) 
        cout << ((num >> i) & 1);
    cout << endl;
}

void check_cs(int &num) {
    int ch = 0;     // здесь будут храниться ошибки
    bool cs_cnt[3], bits[8];
    for (int i = 0; i < 8; i++)
        bits[i] = (num >> i) & 1;  
    cs_cnt[0] = bits[1] ^ bits[3] ^ bits[5] ^ bits[7];
    cs_cnt[1] = bits[2] ^ bits[3] ^ bits[6] ^ bits[7];
    cs_cnt[2] = bits[4] ^ bits[5] ^ bits[6] ^ bits[7];
    for (int i = 0; i < 3; i++) {
        if (cs_cnt[i] == 1)
            ch |= (1 << i);
    }
    bits[ch] = ~bits[ch] & 1;   // инвертируем, берем нулевой (наш) бит
    num &= 0;
    for (int i = 0; i < 8; i++)
        num |= bits[i] << i;
}

int to_true(int num) {
    bool zero_bit = (num >> 3) & 1;  // наш нулевой бит, который сейчас третий
    num = (num >> 4 & 0b00001111) | zero_bit;
    return num;
}



int main()
{
    int coded_num = 0, num1, num2, true_num;
    int ch;
    cout << "To enter a decimal num enter 1, to enter a binary num enter 2, to exit enter -1: ";
    cin >> ch;
    while (ch != -1){
        if (ch == 2) {
            char bin_num[16];
            cin >> bin_num;
            for (int i = 0; i < 16; i++) {
                coded_num |= (bin_num[i] - '0') << (15 - i);    // порядок инвертитровался
            }
        }
        else 
            cin >> coded_num;
        num1 = coded_num >> 8;
        num2 = coded_num ^ (num1 << 8);
        check_cs(num1);
        check_cs(num2);
        true_num = (to_true(num1) << 4) | to_true(num2);
        cout << "Decimal: " << true_num << endl;
        cout << "Binary: ";
        to_bits(true_num);
        cout << "To enter a decimal num enter 1, to enter a binary num enter 2, to exit enter -1: ";
        cin >> ch;
    }
    return 0;
}
