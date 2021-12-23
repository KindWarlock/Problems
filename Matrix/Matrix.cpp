#include "Matrix.h"
Matrix::Matrix(int rows_num, int cols_num) {
    rows = new Vector<Vector<int>>(rows_num);
    for (int i = 0; i < rows_num; i++) {
        Vector<int> row(cols_num);
        rows->insert(row, i);
    }
}

Vector<int>& Matrix::operator[](int index)
{
    return rows[index];
}
