#include "Vector.h"
class Matrix {
    Vector<Vector<int>> *rows;
	bool inSize(bool col, int size);
public:
    Matrix(int rows_num = 3, int cols_num = 3);
    Vector<int>& operator[] (int index);
	int getRowsNum();

    bool insertRow(Vector<int> row);
    bool insertColumn(Vector<int> col);
    /*Matrix& operator +=(const Matrix m2);
    Matrix operator +(const Matrix m2) const;
    Matrix& operator -=(const Matrix m2);
    Matrix operator -(const Matrix m2) const;
    //matrix * int
    Matrix& operator *=(const Matrix m2);
    Matrix operator *(const Matrix m2) const;
    // reverse matrix
    Matrix& operator /=(const Matrix m2);
    Matrix operator /(const Matrix m2) const;
    //dilimiter
    //transpose
    //rank*/
    friend std::ostream& operator <<(std::ostream& out, Matrix& mrx);
};