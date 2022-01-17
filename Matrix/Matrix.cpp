#include "Matrix.h"

Matrix::Matrix() {
	rows = new Vector<Vector<double>>;
}

Matrix::Matrix(int rows_num, int cols_num) {
	rows = new Vector<Vector<double>>(rows_num);
	for (int i = 0; i < rows_num; i++) {
		Vector<double> row(cols_num);
		for (int i = 0; i < cols_num; i++) {
			row.insert(0);
		}
		rows->insert(row);
	}
}

Matrix::Matrix(const Matrix& mrx) {
	int rows_num = mrx.getRowsNum();
	rows = new Vector<Vector<double>>(rows_num);
	for (int i = 0; i < rows_num; i++) {
		rows->insert(mrx[i]);
	}
}

Matrix::~Matrix() {
	delete rows;
}

int Matrix::getRowsNum() const{
	return rows->getSize();
}

int Matrix::getColumnsNum() const{
	return (*rows)[0].getSize();
}

Matrix& Matrix::operator=(const Matrix m2)
{
	while (getRowsNum() > m2.getRowsNum()) {
		rows->remove(getRowsNum() - 1);
	}
	while (getColumnsNum() > m2.getColumnsNum()) {
		for (int i = 0; i < getRowsNum(); i++) {
			(*rows)[i].remove(getColumnsNum() - 1);
		}
		
	}
	for (int i = 0; i < m2.getColumnsNum(); i++) {
		(*rows)[i] = m2[i];
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& m2)
{
	if (!inSize(true, m2.getColumnsNum()) || !inSize(false, m2.getRowsNum())) {
		cout << "Can't add" << endl;
	}
	else {
		for (int i = 0; i < getColumnsNum(); i++) {
			for (int k = 0; k < getRowsNum(); k++) {
				(*rows)[i][k] += m2[i][k];
			}
		}
	}
	return *this;
}

Matrix Matrix::operator+(Matrix& m2) const
{
	Matrix m1(*this);
	m1 += m2;
	return m1;
}

Matrix Matrix::operator-() const
{
	Matrix m(*this);
	m *= -1;
	return m;
}

Matrix& Matrix::operator-=(const Matrix& m2)
{
	return *this += -m2;
}

Matrix Matrix::operator-(const Matrix m2) const
{
	Matrix m1(*this);
	m1 -= m2;
	return m1;
}

Matrix& Matrix::operator*=(double a)
{
	for (int i = 0; i < getRowsNum(); i++) {
		for (int k = 0; k < getColumnsNum(); k++) {
			(*rows)[i][k] *= a;
		}
	}
	return *this;
}

Matrix Matrix::operator*(double a) const
{
	Matrix m1(*this);
	m1 *= a;
	return m1;
}

Matrix& Matrix::operator*=(const Matrix& m2)
{
	int m2_rows = m2.getRowsNum(),
		m2_cols = m2.getColumnsNum(),
		m1_rows = getRowsNum(),
		m1_cols = getColumnsNum();
	if (m1_cols == m2_rows) {
		for (int i = 0; i < m1_rows; i++) {
			Vector<double> new_row(m1_cols);
			for (int k = 0; k < m2_cols; k++) {
				double mult = 0.0;
				for (int j = 0; j < m1_cols; j++) {
					mult += (*rows)[i][j] * m2[j][k];
				}
				new_row.insert(mult);
			}
			(*rows)[i] = new_row;
		}
	}
	else {
		cout << "Can't multiply" << endl;
	}
	return *this;
}

Matrix Matrix::operator*(const Matrix m2) const
{
	Matrix m1(*this);
	m1 *= m2;
	return m1;
}

Matrix Matrix::findMinor(int posY, int posX) const
{
	int rows_num = getRowsNum(),
		cols_num = getColumnsNum();
	bool right_index = posY < rows_num && posY >= 0 && posX >= 0 && posX < cols_num;
	Matrix m(rows_num - 1, cols_num - 1);
	if (!right_index) {
		cout << "Wrong index";
		return m;
	}
	int rows_flag = 0;
	for (int i = 0; i < rows_num; i++) {
		if (i == posY) {
			rows_flag = 1;
			continue;
		}
		int cols_flag = 0;
		for (int k = 0; k < cols_num; k++) {
			if (k == posX) {
				cols_flag = 1;
				continue;
			}
			// вычитаем флаги из номера строки/столбца (0 - не было пересечения с posY/posX, 1 - было)
			m[i - rows_flag][k - cols_flag] = (*rows)[i][k];
		}
	}
	return m;
}

double Matrix::findDeterminant() const
{
	int rows_num = getRowsNum(),
		cols_num = getColumnsNum();
	if (rows_num != cols_num) {
		cout << "Number of rows should be equal to number of columns\n";
		return -0.0;
	}
	if (rows_num < 2) {
		cout << "Matrix should be bigger\n";
		return -0.0;
	}
	if (rows_num == 2) {
		return findDeterminant2();
	}
	if (rows_num == 3) {
		return findDeterminant3();
	}
	double det = 0.0;
	int sign = 1; // 1 для +, -1 для -
	for (int k = 0; k < cols_num; k++) {
		if (k % 2 == 0)
			sign = 1;
		else
			sign = -1;
		Matrix minor(findMinor(0, k));
		det += sign * (*rows)[0][k] * minor.findDeterminant();
	}
	return det;
}

Matrix Matrix::reverse() const
{
	int rows_num = getRowsNum(),
		cols_num = getColumnsNum();
	if (rows_num != cols_num) {
		cout << "Number of rows should be equal to number of columns\n";
		return (*this);
	}
	if (rows_num < 2) {
		cout << "Matrix should be bigger\n";
		return (*this);
	}
	double det = findDeterminant();
	if (det == 0) {
		cout << "Can't reverse matrix\n";
		return (*this);
	}
	Matrix m(rows_num, cols_num);
	int sign = 1; // 1 для +, -1 для -
	for (int i = 0; i < rows_num; i++) {
		for (int k = 0; k < cols_num; k++) {
			if ((i + k) % 2 == 0)
				sign = 1;
			else
				sign = -1;
			Matrix minor(findMinor(i, k));
			m[i][k] = sign * minor.findDeterminant();
		}
	}
	return m.transpose() * (1 / det);
}

Matrix& Matrix::operator/=(const Matrix m2)
{
	(*this) *= m2.reverse();
	return *this;
}

Matrix Matrix::operator/(const Matrix m2) const
{
	Matrix m(*this);
	m /= m2;
	return m;
}

Vector<double>& Matrix::operator[](int index) const
{
	return (*rows)[index];
}

bool Matrix::inSize(bool col, int size) {
	if (col) {
		if (size == getRowsNum())
			return true;
	}
	else {
		if (size == getColumnsNum())
			return true;
	}
	return false;
}

double Matrix::findDeterminant2() const
{
	return (*rows)[0][0] * (*rows)[1][1] - (*rows)[0][1] * (*rows)[1][0];
}

double Matrix::findDeterminant3() const
{
	double main_diag = (*rows)[0][0] * (*rows)[1][1] * (*rows)[2][2],
		   main_triangle1 = (*rows)[0][1] * (*rows)[1][2] * (*rows)[2][0],
	       main_triangle2 = (*rows)[0][2] * (*rows)[2][1] * (*rows)[1][0],
		   other_diag = (*rows)[0][2] * (*rows)[1][1] * (*rows)[2][0],
		   other_triangle1 = (*rows)[0][1] * (*rows)[2][2] * (*rows)[1][0],
		   other_triangle2 = (*rows)[2][1] * (*rows)[0][0] * (*rows)[1][2];
	return main_diag + main_triangle1 + main_triangle2 - other_diag - other_triangle1 - other_triangle2;
}

bool Matrix::insertRow(Vector<double>& row) {
	if (rows -> getSize() != 0 && !inSize(false, row.getSize())) {
		return false;
	}

	rows->insert(row);
	return true;
}

bool Matrix::insertColumn(Vector<double>& col) {
	if (rows->getSize() == 0) {
		for (int i = 0; i < col.getSize(); i++) {
			Vector<double> row;
			row.insert(col[i]);
			rows->insert(row);
		}
		return true;
	}
	else if (!inSize(true, col.getSize())) {
		return false;
	}
	for (int i = 0; i < col.getSize(); i++) {
		(*rows)[i].insert(col[i]);
	}
	return true;
}

Matrix& Matrix::transpose() {
	Matrix* mrx = new Matrix;
	for (int i = 0; i < getRowsNum(); i++) {
		Vector<double> row = (*rows)[i];
		mrx->insertColumn(row);
	}
	return *mrx;
}

std::ostream& operator <<(std::ostream& out, Matrix& mrx) {
	/*
	//выравнивание по наибольшему количеству чисел
	int max_dig = 0;
	for (int i = 0; i < mrx.getRowsNum(); i++) {
		for (int k = 0; k < mrx.getColumnsNum(); k++) {
			if (std::to_string(mrx[i][k]).length() > max_dig)
				max_dig = std::to_string(mrx[i][k]).length();
		}
	}
	*/
	for (int i = 0; i < mrx.getRowsNum(); i++) {
		out << mrx[i];
	}
	return out;
}