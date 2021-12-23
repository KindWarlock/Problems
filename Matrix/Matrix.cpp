#include "Matrix.h"

Matrix::Matrix(int rows_num, int cols_num) {
    rows = new Vector<Vector<int>>(rows_num);
    for (int i = 0; i < rows_num; i++) {
		Vector<int> row(cols_num);
		for (int i = 0; i < cols_num; i++) {
			row.insert(0);
		}
		rows->insert(row);
    }
}

int Matrix::getRowsNum() {
	return rows->getSize();
}

Vector<int>& Matrix::operator[](int index)
{
    return (*rows)[index];
}

bool Matrix::inSize(bool col, int size) {
	if (col) {
		if (size == rows->getSize())
			return true;
	}
	else {
		if (size == (*rows)[0].getSize())
			return true;
	}
	return false;
}

bool Matrix::insertRow(Vector<int> row) {
	if (!inSize(false, row.getSize())) {
		return false;
	}

	rows->insert(row);
	return true;
}

bool Matrix::insertColumn(Vector<int> col) {
	if (!inSize(true, col.getSize())) {
		return false;
	}
	for (int i = 0; i < rows->getSize(); i++) {
		(*rows)[i].insert(col[i]);
	}
	return true;
}

std::ostream& operator <<(std::ostream& out, Matrix& mrx) {
	for (int i = 0; i < mrx.getRowsNum(); i++) {
		out << mrx[i];
	}
	return out;
}