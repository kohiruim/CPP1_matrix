# s21_matrix+

Реализация библиотеки для работы с матрицами, используя объектно-ориентированный подход.

## Information

- Полное покрытие unit-тестами функций библиотеки c GTest
- Makefile с целями all, clean, test, s21_matrix_oop.a

### Операции над матрицами

Ниже представлены операции над матрицами, которые реализованы в библиотеке.

| Операция    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `bool EqMatrix(const S21Matrix& other)` | Проверяет матрицы на равенство между собой |  |
| `void SumMatrix(const S21Matrix& other)` | Прибавляет вторую матрицы к текущей | различная размерность матриц |
| `void SubMatrix(const S21Matrix& other)` | Вычитает из текущей матрицы другую | различная размерность матриц |
| `void MulNumber(const double num)` | Умножает текущую матрицу на число |  |
| `void MulMatrix(const S21Matrix& other)` | Умножает текущую матрицу на вторую | число столбцов первой матрицы не равно числу строк второй матрицы |
| `S21Matrix Transpose()` | Создает новую транспонированную матрицу из текущей и возвращает ее |  |
| `S21Matrix CalcComplements()` | Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее | матрица не является квадратной |
| `double Determinant()` | Вычисляет и возвращает определитель текущей матрицы | матрица не является квадратной |
| `S21Matrix InverseMatrix()` | Вычисляет и возвращает обратную матрицу | определитель матрицы равен 0 |

Реализованы конструкторы и деструкторы:

| Метод    | Описание   |
| ----------- | ----------- |
| `S21Matrix()` | Базовый конструктор, инициализирующий матрицу некоторой заранее заданной размерностью |  
| `S21Matrix(int rows, int cols)` | Параметризированный конструктор с количеством строк и столбцов | 
| `S21Matrix(const S21Matrix& other)` | Конструктор копирования |
| `S21Matrix(S21Matrix&& other)` | Конструктор переноса |
| `~S21Matrix()` | Деструктор |

Реализована перегрузка операторов:

| Оператор    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `+`      | Сложение двух матриц  | различная размерность матриц |
| `-`   | Вычитание одной матрицы из другой | различная размерность матриц |
| `*`  | Умножение матриц и умножение матрицы на число | число столбцов первой матрицы не равно числу строк второй матрицы |
| `==`  | Проверка на равенство матриц (`EqMatrix`) | |
| `=`  | Присвоение матрице значений другой матрицы | |
| `+=`  | Присвоение сложения (`SumMatrix`)   | различная размерность матриц |
| `-=`  | Присвоение разности (`SubMatrix`) | различная размерность матриц |
| `*=`  | Присвоение умножения (`MulMatrix`/`MulNumber`) | число столбцов первой матрицы не равно числу строк второй матрицы |
| `(int i, int j)`  | Индексация по элементам матрицы (строка, колонка) | индекс за пределами матрицы |