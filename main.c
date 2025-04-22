//Проверено
#include "matrix.h"
#include "arithmetic.h"
#include "other.h"
#include "exp+gauss.h"
int main()
{
  //  setlocale(LC_ALL,"RUS");
    puts("1)Test matrix.h");
    puts("2)Test arithmetic.h");
    puts("3)Test other.h");
    puts("4)Test exp+gauss.h");
    int i;
    scanf("%d",&i);
    if(i==1){
    matrix *m=matrix_alloc(2,2);
    vvod(m);vivod(m);puts("");
    matrix *mcopy=matrix_copy(m);
    matrix_set_id(m);vivod(m);puts("");
    matrix_set_zero(m);vivod(m);puts("");
    vivod(mcopy);puts("");
    matrix *x=matrix_alloc_id(2,2);vivod(x);puts("");
    matrix *y=matrix_alloc_zero(2,2);vivod(y);puts("");
    matrix_realloc(m,3,3);
    matrix_set_id(m);vivod(m);puts("");
    matrix_free(m); matrix_free(mcopy); matrix_free(x); matrix_free(y);
    }else if(i==2){
        matrix *A=matrix_alloc(3,3);
        *matrix_ptr(A, 0, 0) = 1.0; *matrix_ptr(A, 0, 1) = 2.0; *matrix_ptr(A, 0, 2) = 3.0;
        *matrix_ptr(A, 1, 0) = 4.0; *matrix_ptr(A, 1, 1) = 5.0; *matrix_ptr(A, 1, 2) = 6.0;
        *matrix_ptr(A, 2, 0) = 7.0; *matrix_ptr(A, 2, 1) = 8.0; *matrix_ptr(A, 2, 2) = 9.0;
        matrix *B=matrix_alloc(3,3);
        *matrix_ptr(B, 0, 0) = 1.0; *matrix_ptr(B, 0, 1) = 2.0; *matrix_ptr(B, 0, 2) = 3.0;
        *matrix_ptr(B, 1, 0) = 4.0; *matrix_ptr(B, 1, 1) = 5.0; *matrix_ptr(B, 1, 2) = 6.0;
        *matrix_ptr(B, 2, 0) = 7.0; *matrix_ptr(B, 2, 1) = 8.0; *matrix_ptr(B, 2, 2) = 9.0;
        matrix_add(A,B);vivod(A);
        matrix_sub(A,B);vivod(A);
        matrix_smul(A,5);vivod(A);
        matrix_sdiv(A,5);vivod(A);
        matrix *m=matrix_alloc(3,3);
        matrix_add2(m,A,B);vivod(m);
        matrix_sub2(m,A,B);vivod(m);
        matrix_smul2(m,B,10);vivod(m);
        matrix_sdiv2(m,B,10);vivod(m);
        matrix_mul(B,A);vivod(B);
        matrix_mul2(m,A,B);vivod(m); //m = A * (B * A)
        matrix_free(A);matrix_free(B);matrix_free(m);
    } else if(i==3){
        matrix *A=matrix_alloc(3,3);
        *matrix_ptr(A, 0, 0) = 1.0; *matrix_ptr(A, 0, 1) = 2.0; *matrix_ptr(A, 0, 2) = 3.0;
        *matrix_ptr(A, 1, 0) = 4.0; *matrix_ptr(A, 1, 1) = 5.0; *matrix_ptr(A, 1, 2) = 6.0;
        *matrix_ptr(A, 2, 0) = 7.0; *matrix_ptr(A, 2, 1) = 8.0; *matrix_ptr(A, 2, 2) = 9.0;
        vivod(A);matrix_T(A);vivod(A);matrix_T(A);
        change_stroki(A,1,2);vivod(A);
        change_stolb(A,1,2);vivod(A);
        mul_stroka(A,2,10);vivod(A);
        div_stroka(A,2,10);vivod(A);
        dve_stroki(A,2,1,50);vivod(A);
        printf("\n%.2lf",norma(A));
        matrix_free(A);
    }else if(i==4){
        puts("TEST EXP");
        matrix *m = matrix_alloc(3, 3);
        *matrix_ptr(m, 0, 0) = 1.0; *matrix_ptr(m, 0, 1) = 0.0; *matrix_ptr(m, 0, 2) = 0.0;
        *matrix_ptr(m, 1, 0) = 0.0; *matrix_ptr(m, 1, 1) = 2.0; *matrix_ptr(m, 1, 2) = 0.0;
        *matrix_ptr(m, 2, 0) = 0.0; *matrix_ptr(m, 2, 1) = 0.0; *matrix_ptr(m, 2, 2) = -1.0;
        vivod(m);
        matrix * otvet = matrix_alloc(3,3);
        matrix_exp(otvet,m,ERROR); vivod(otvet);
        matrix_free(m); matrix_free(otvet);

        puts("\nTEST GAUSS");
        matrix *A = matrix_alloc(3, 3);
        *matrix_ptr(A, 0, 0) = 2.0; *matrix_ptr(A, 0, 1) = 1.0; *matrix_ptr(A, 0, 2) = -1.0;
        *matrix_ptr(A, 1, 0) = 4.0; *matrix_ptr(A, 1, 1) = 1.0; *matrix_ptr(A, 1, 2) = 0.0;
        *matrix_ptr(A, 2, 0) = -2.0; *matrix_ptr(A, 2, 1) = 1.0; *matrix_ptr(A, 2, 2) = 2.0;
        vivod(A);
         matrix *B = matrix_alloc(3, 1);
        *matrix_ptr(B, 0, 0) = 1.0;
        *matrix_ptr(B, 1, 0) = -2.0;
        *matrix_ptr(B, 2, 0) = 7.0;
        vivod(B);

        matrix *X = gauss(A,B);
        vivod(X);
        matrix_free(X);
        matrix_free(A);
        matrix_free(B);




    }else return 0;

    return 0;
}
