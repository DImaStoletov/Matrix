#ifndef EXPGAUSS_H_INCLUDED
#define EXPGAUSS_H_INCLUDED
#include "matrix.h"
#include "arithmetic.h"
#include "other.h"
#include <float.h>
#define ERROR  1e-10
//Матричная экспонента
int matrix_exp(matrix *m, const matrix *A, double eps);

//Решение СЛАУ: метод Гаусса
matrix* gauss(const matrix* A, const matrix* B);
#endif // EXPGAUSS_H_INCLUDED
