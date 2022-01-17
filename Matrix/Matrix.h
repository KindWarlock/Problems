#include "Vector.h"
#include <iostream>
#include <string>
class Matrix {
    Vector<Vector<double>>* rows;
    bool inSize(bool col, int size);
    //определитель для матрицы 2х2
    double findDeterminant2() const;
    //определитель для матрицы 3х3
    double findDeterminant3() const;
public:
    Matrix();
    Matrix(int rows_num, int cols_num);
    Matrix(const Matrix& mrx);
    ~Matrix();

    Vector<double>& operator[] (int index) const;
    bool insertRow(Vector<double>& row);
    bool insertColumn(Vector<double>& col);
    int getRowsNum() const;
    int getColumnsNum() const;
    Matrix& transpose();
    Matrix findMinor(int posY, int posX) const;
    double findDeterminant() const;
    Matrix reverse() const;
    Matrix& operator =(const Matrix m2);
    Matrix& operator +=(const Matrix& m2);
    Matrix operator +(Matrix& m2) const;
    Matrix operator -() const;
    Matrix& operator -=(const Matrix& m2);
    Matrix operator -(const Matrix m2) const;
    Matrix& operator *=(double a);
    Matrix operator *(double a) const;
    Matrix& operator *=(const Matrix& m2);
    Matrix operator *(const Matrix m2) const;
    Matrix& operator /=(const Matrix m2);
    Matrix operator /(const Matrix m2) const;
    friend std::ostream& operator <<(std::ostream& out, Matrix& mrx);
};
