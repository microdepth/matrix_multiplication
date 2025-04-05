#ifndef MATRIX_MULTIPLICATION_MATRIX_H
#define MATRIX_MULTIPLICATION_MATRIX_H

#include <iostream>

class Matrix {
public:
    Matrix(int rows, int cols);
    ~Matrix();

    Matrix operator*(const Matrix& other) const;

    void set_value(int row, int col, int value);
    int get_value(int row, int col) const;
    int get_rows() const;
    int get_cols() const;
    int** get_matrix() const;
    void fill_matrix();

private:
    int rows;
    int cols;
    int** imatrix;

    void allocate_memory();
    void deallocate_memory();
};

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);


#endif // MATRIX_MULTIPLICATION_MATRIX_H
