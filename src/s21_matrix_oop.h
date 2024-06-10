#ifndef CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H
#define EPS 1E-7
#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  // конструкторы и деструкторы
  S21Matrix(int const rows, int const cols);
  S21Matrix() : S21Matrix(1, 1){};
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  void Print();  // для теста

  // аксессоры и мутатор
  int GetRows() const;
  int GetCols() const;
  void SetRows(const int rows);
  void SetCols(const int cols);

  // операции над матрицами
  /*bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose() const;
  double Determinant() const;
  S21Matrix CalcComplements() const;
  S21Matrix InverseMatrix() const;*/

  // перегрузка операторов
  // S21Matrix operator+(const S21Matrix &other);
  // S21Matrix operator-(const S21Matrix &other);
  // S21Matrix operator*(const S21Matrix &other);
  // S21Matrix operator*(const double num);
  // bool operator==(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator=(S21Matrix &&other);
  // S21Matrix &operator+=(const S21Matrix &other);
  // S21Matrix &operator-=(const S21Matrix &other);
  // S21Matrix &operator*=(const S21Matrix &other);
  // S21Matrix &operator*=(const double num);
  double &operator()(int i, int j);

  // для константных матриц
  /*S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix operator*(const double num) const;
  bool operator==(const S21Matrix &other) const;*/
  double operator()(int i, int j) const;

 private:
  int rows_ = 0, cols_ = 0;
  double **matrix_ = nullptr;

  // всякие допы
  void DeleteMatrix();
  void CreateMatrix(int rows, int cols);
  // void MiniMatrix(S21Matrix &mini, int row, int column) const;
};

#endif  // CPP1_S21_MATRIXPLUS_1_S21_MATRIX_OOP_H