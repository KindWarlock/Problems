#include "Vector.h"
class Matrix {
    Vector<Vector<int>> *rows;
public:
    Matrix(int rows_num = 4, int cols_num = 4);
    const Vector<int>& operator[] (int index);

    /*void insertRow(Vector<int> row);
    void insertColumn(Vector<int> col);
    Matrix& operator +=(const Matrix m2);
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
    //rank
    friend std::ostream& operator <<(std::ostream& out, Matrix& mrx);*/
};
