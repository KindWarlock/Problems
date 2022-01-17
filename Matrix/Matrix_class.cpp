#include <iostream>
#include "Matrix.h"
#include "cmath"
using namespace std;

void fill_matrix(Matrix& m) {
	double cnt = 0.0;
	for (int i = 0; i < m.getRowsNum(); i++) {
		for (int k = 0; k < m.getColumnsNum(); k++) {
			m[i][k] = cnt++;
		}
	}
	m[1][2] = 2;
}

int main() {
	//создание матрицы
	Matrix m(3, 3);
	fill_matrix(m);
	cout << m << endl;

	//добавление ряда
	Vector<double> row(3);
	for (int i = 0; i < 3; i++) {
		row.insert(i);
	}
	m.insertRow(row);
	cout << m << endl;

	//добавление столбца
	Vector<double> col(4);
	for (int i = 0; i < 4; i++) {
		col.insert(i);
	}
	m.insertColumn(col);
	cout << m << endl;
	
	//поиск определителя
	cout << "Determinant: " << m.findDeterminant() << "\n\n";

	//присвоение матрицы и обратная матрица
	Matrix temp_m = m.reverse();
	cout << "Reversed:\n" << temp_m << endl;

	//проверка обратной матрицы и умножение
	temp_m = temp_m * m;
	cout << "Identity matrix:\n" << temp_m << endl;

	//деление матрицы на саму себя:
	temp_m = m / m;
	cout << "Divided:\n" << temp_m << endl;
	
	//транспонирование:
	temp_m = m.transpose();
	cout << "Transposed:\n" << temp_m << endl;

	//вычитание и сложение изначальной 4х4 и транспонированной
	temp_m = m - temp_m;
	cout << "Subtracted:\n" << temp_m << endl;
	temp_m = m - temp_m;
	temp_m = m + temp_m;
	cout << "Added:\n" << temp_m << endl;

	//умножение на число
	temp_m = m * 2.0;
	cout << "Multiply by number (2):\n" << temp_m << endl;

	//нахождение минора
	temp_m = m.findMinor(0,2);
	cout << "Minor (0, 2):\n" << temp_m << endl;

	return 0;
}
