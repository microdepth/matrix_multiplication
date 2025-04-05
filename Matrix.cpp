#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), imatrix(nullptr) {
    allocate_memory();
}
Matrix::~Matrix() {
    deallocate_memory();
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("matrix dimensions are incompatible for multiplication.");
    }

    Matrix product(rows, other.cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            int sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += imatrix[i][k] * other.imatrix[k][j];
            }
            product.imatrix[i][j] = sum;
        }
    }

    return product;
}
std::ostream& operator<<(std::ostream& stream, const Matrix& matrix) {
    for (int i = 0; i < matrix.get_rows(); i++) {
        for (int j = 0; j < matrix.get_cols(); j++) {
            stream << matrix.get_matrix()[i][j] << " ";
        }
        stream << std::endl;
    }
    return stream;
}

void Matrix::set_value(int row, int col, int value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        imatrix[row][col] = value;
    }
}
int Matrix::get_value(int row, int col) const {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return imatrix[row][col];
    }
    return 0;
}
int Matrix::get_rows() const {
    return rows;
}
int Matrix::get_cols() const {
    return cols;
}
int** Matrix::get_matrix() const {
    return imatrix;
}

void Matrix::allocate_memory() {
    imatrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        imatrix[i] = new int[cols];
    }
}
void Matrix::deallocate_memory() {
    for (int i = 0; i < rows; i++) {
        delete[] imatrix[i];
    }
    delete[] imatrix;
}

void Matrix::fill_matrix() {
    int num;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "number for row " << i+1 << " and column " << j+1 << '\n';
            std::cin >> num;
            set_value(i, j, num);
        }
    }

}


