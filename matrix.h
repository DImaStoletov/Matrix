#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <locale.h>
#include <math.h>
typedef struct matrix matrix;
//доступ к количеству строк/столбцов
size_t m_w(const matrix* m);
size_t m_h(const matrix* m);
//инициализация динамического массива
matrix * matrix_alloc (size_t w, size_t h);
//копирование матрицы
matrix * matrix_copy (const matrix *m);
//освобождение памяти
void matrix_free (matrix *m);
//доступ к элементу, неконстантный случай
double * matrix_ptr (matrix *m, size_t i, size_t j);
//доступ к элементу, константный случай
const double * matrix_cptr (const matrix *m, size_t i, size_t j);
// Зануление матрицы
void matrix_set_zero (matrix *m);
//Сделать матрицу единичной
void matrix_set_id (matrix *m);   // Сделать единичной
//создание нулевой матрицы
matrix * matrix_alloc_zero (size_t w, size_t h);
//создание единичной матрицы
matrix * matrix_alloc_id (size_t w, size_t h);
//присваивание без инициализации
int matrix_assign (matrix *m1, const matrix *m2);
//ввод матрицы с клавиатуры
void vvod(matrix *m);
//вывод матрицы в консоль
void vivod(const matrix *m);
//изменение размеров матрицы
matrix * matrix_realloc(matrix * m,size_t w, size_t h);
#endif // MATRIX_H_INCLUDED
