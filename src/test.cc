#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

// тест сеттера
TEST(SET_TEST, TestCase_1) { S21Matrix matrix(2, 2); }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}