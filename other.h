#ifndef OTHER_H_INCLUDED
#define OTHER_H_INCLUDED
#include "matrix.h"

//транспонирование матрицы
matrix * matrix_T(matrix * m);
//перестановка строк по номеру, не по индексу
void change_stroki(matrix *m,size_t x,size_t y);
//перестановка столбцов по номеру, не по индексу
void change_stolb(matrix *m,size_t x,size_t y);
//Умножение строки на число
void mul_stroka(matrix *m,size_t x,double data);
//деление строки на число
void div_stroka(matrix *m,size_t x,double data);
//прибавление к строке другую строку умноженную на скаляр
void dve_stroki(matrix *m,size_t x,size_t y, double data);
//норма матрицы (максимальная сумма строки)
double norma(const matrix *m);
#endif // OTHER_H_INCLUDED
