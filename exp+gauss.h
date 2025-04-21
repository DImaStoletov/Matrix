#ifndef EXPGAUSS_H_INCLUDED
#define EXPGAUSS_H_INCLUDED
#include "matrix.h"
#include "arithmetic.h"
#include "other.h"
//Матричная экспонента
int matrix_exp(matrix *m, const matrix *A, double eps);

//Решение СЛАУ: метод Гаусса
#endif // EXPGAUSS_H_INCLUDED
