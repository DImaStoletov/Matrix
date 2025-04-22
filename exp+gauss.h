#ifndef EXPGAUSS_H_INCLUDED
#define EXPGAUSS_H_INCLUDED
#include "matrix.h"
#include "arithmetic.h"
#include "other.h"
#include <float.h>
#define ERROR  1e-10
//��������� ����������
int matrix_exp(matrix *m, const matrix *A, double eps);

//������� ����: ����� ������
matrix* gauss(const matrix* A, const matrix* B);
#endif // EXPGAUSS_H_INCLUDED
