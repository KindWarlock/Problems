#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix test_m(3, 3);
	cout << test_m << endl;

	Vector<int> test_col(3);
	int rat[3] = {1,1,1};
	test_col.insert(rat, 3);

	Vector<int> test_row(4);
	int cat[4] = {4,4,4,4};
	test_row.insert(cat, 4);

	test_m.insertColumn(test_col);
	cout << test_m<< endl;
	test_m.insertRow(test_row);
	cout << test_m << endl;
	
	cout << "transposed: " << endl;
	Matrix tr(test_m.transpose());
	cout << tr;
	system("pause");
    return 0;
}