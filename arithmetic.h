#ifndef ARITHMETIC_H_INCLUDED
#define ARITHMETIC_H_INCLUDED
#include "matrix.h"

//сложение m1+=m2
int matrix_add (matrix *m1, const matrix *m2);
//вычитание m1-=m2
int matrix_sub (matrix *m1, const matrix *m2);
//умножение m*=d
void matrix_smul (matrix *m, double d);
//деление m/=d
void matrix_sdiv (matrix *m, double d);
// m = m1 + m2
int matrix_add2 (matrix *m, const matrix *m1, const matrix *m2);
//m = m1 - m2
int matrix_sub2 (matrix *m, const matrix *m1, const matrix *m2);
//m = m1 * d
int matrix_smul2 (matrix *m, const matrix *m1, double d);
//m = m1 / d
int matrix_sdiv2 (matrix *m, const matrix *m1, double d);




// m1 *= m2
int matrix_mul(matrix *m1, const matrix *m2);
// m = m1 * m2
int matrix_mul2(matrix *m, const matrix *m1, const matrix *m2);
#endif // ARITHMETIC_H_INCLUDED
