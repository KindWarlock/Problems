#include "Vector.h"
class Matrix {
    Vector<Vector<int>> *rows;
	bool inSize(bool col, int size);
public:
    Matrix(int rows_num = 3, int cols_num = 3);
	Matrix(Matrix& mrx);
    ~Matrix();

    Vector<int>& operator[] (int index);
    bool insertRow(Vector<int> row);
    bool insertColumn(Vector<int> col);
    int getRowsNum();
    int getColumnsNum();
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
    //rank*/
	Matrix transpose();
    friend std::ostream& operator <<(std::ostream& out, Matrix& mrx);
};