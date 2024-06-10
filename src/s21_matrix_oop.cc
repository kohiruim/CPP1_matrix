#include "s21_matrix_oop.h"

S21Matrix::S21Matrix(int const rows, int const cols) {
  CreateMatrix(rows, cols);
}

S21Matrix::~S21Matrix() { DeleteMatrix(); }

S21Matrix::S21Matrix(const S21Matrix &other) {
  CreateMatrix(other.rows_, other.cols_);
  for (int row = 0; row < rows_; ++row) {
    for (int column = 0; column < cols_; ++column) {
      matrix_[row][column] = other.matrix_[row][column];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
}

int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int newRows) {
  if (newRows < 1)
    throw std::out_of_range("Количество строк и столбцов - натуральные числа");
  if (newRows != rows_) {
    S21Matrix newMatrix(newRows, cols_);
    int minRow = std::min(newRows, rows_);
    for (int row = 0; row < minRow; ++row) {
      for (int column = 0; column < cols_; ++column) {
        newMatrix.matrix_[row][column] = matrix_[row][column];
      }
    }
    *this = newMatrix;
  }
}

void S21Matrix::SetCols(int newCols) {
  if (newCols < 1)
    throw std::out_of_range("Количество строк и столбцов - натуральные числа");
  if (newCols != rows_) {
    S21Matrix newMatrix(rows_, newCols);
    int minCols = std::min(newCols, cols_);
    for (int row = 0; row < rows_; ++row) {
      for (int column = 0; column < newCols; ++column) {
        newMatrix.matrix_[row][column] = matrix_[row][column];
      }
    }
    *this = newMatrix;
  }
}

void S21Matrix::CreateMatrix(int rows, int cols) {
  if (rows < 1 || cols < 1)
    throw std::out_of_range("Количество строк и столбцов - натуральные числа");
  DeleteMatrix();
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double *[rows]();
  for (int i = 0; i < rows; i++) {
    matrix_[i] = new double[cols]();
  }
}

void S21Matrix::DeleteMatrix() {
  if (matrix_ != nullptr) {
    std::cout << "\ndestructor";
    for (int row = 0; row < rows_; ++row) {
      delete[] matrix_[row];
    }
    delete[] matrix_;
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

double &S21Matrix::operator()(int i, int j) {
  if (i >= rows_ || i < 0 || j >= cols_ || j < 0)
    throw std::out_of_range("Неверный индекс");
  return matrix_[i][j];
}

double S21Matrix::operator()(int i, int j) const {
  if (i >= rows_ || i < 0 || j >= cols_ || j < 0)
    throw std::out_of_range("Неверный индекс");
  return matrix_[i][j];
}

void S21Matrix::Print() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      std::cout << matrix_[i][j] << " ";
    }
    std::cout << "\n";
  }
}

// Оператор присваивания копированием
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    S21Matrix res(other);
    *this = std::move(res);
  }
  return *this;
}

// Оператор присваивания перемещением
S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  if (this != &other) {
    DeleteMatrix();
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }
  return *this;
}

int main() {
  S21Matrix test(3, 3);
  test(0, 0) = 1.0;
  test(0, 1) = 1.0;
  test(0, 2) = 1.0;
  test(1, 0) = 1.0;
  test(1, 1) = 1.0;
  test(1, 2) = 1.0;
  test(2, 0) = 1.0;
  test(2, 1) = 1.0;
  test(2, 2) = 1.0;

  test.SetRows(5);
  test.Print();
  return 0;
}