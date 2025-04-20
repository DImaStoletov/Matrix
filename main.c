//Проверено
#include "matrix.h"
//Не проверено
#include "arithmetic.h"
int main()
{
    setlocale(LC_ALL,"RUS");
    matrix * m = matrix_alloc(5,5);
    matrix * m1 = matrix_alloc_id(5,5);
    matrix * m2 = matrix_alloc_id(5,5);
    matrix_sdiv2(m,m1,5);
    vivod(m);
    free(m);
    free(m1);
    free(m2);
    return 0;
}
