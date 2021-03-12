#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int NUM = 10000;

int main()
{
    srand(time(NULL));
    int min, max, ar[NUM], k;
    cout << "Enter min x, max x: ";
    cin >> min >> max;
    /* Просто генерация
    for (int i = 0; i < NUM; i++) {
        ar[i] = rand() % (max - min + 1) + min;
        cout << ar[i] << " ";
    }*/
    int rans_num = max - min + 1, num = rans_num;
    int* rans = new int[rans_num];
    for (int i = 0; i < rans_num; i++) {
        rans[i] = i;
    }
    for (int i = 0; i < num; i++) {
        k = rand() % rans_num;
        ar[i] = rans[k];
        rans[k] = rans[rans_num - 1];
        rans_num--;
        cout << ar[i] << " ";
    }
}
