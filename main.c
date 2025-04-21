//Проверено
#include "matrix.h"
#include "arithmetic.h"
#include "other.h"
//Не проверено
#include "exp+gauss.h"
int main()
{
    setlocale(LC_ALL,"RUS");
    matrix * m = matrix_alloc(3,3);
    matrix * A = matrix_alloc(3,3);
//    matrix * m2 = matrix_alloc(3,3);
    vvod(A);
    vivod(A);
    matrix_exp(m,A,0.0001);
    vivod(m);
    matrix_free(m);
    matrix_free(A);
//    matrix_free(m2);
    return 0;
}
