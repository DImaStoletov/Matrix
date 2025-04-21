#include "exp+gauss.h"

int matrix_exp(matrix *m, const matrix *A, double eps){
    if (m == NULL || A == NULL || A->w != A->h || m->w != A->w || m->h != A->h) return -1;
    matrix *x = matrix_alloc(m->h,m->w);
    matrix *y = matrix_alloc(m->h,m->w);
    if (x == NULL || y == NULL) {matrix_free(x); matrix_free(y); return -1;}
    matrix_set_id(m);
    matrix_assign(x, A); //(A^1/1!)
    int k = 1;
    do {
        matrix_add(m, x); //res += A^k/k!
        matrix_mul2(y, x, A); //y=A^k / k * A
        matrix_assign(x, y); //x=A^k / k * A
        matrix_sdiv(x, ++k); //x=A^k / k * A / (k+1) => x = A^(k+1) / (k+1)!
    } while (norma(x) >= eps);
    matrix_free(x); matrix_free(y);
    return 0;
}



