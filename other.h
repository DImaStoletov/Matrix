#ifndef OTHER_H_INCLUDED
#define OTHER_H_INCLUDED
#include "matrix.h"

//���������������� �������
matrix * matrix_T(matrix * m);
//������������ ����� �� ������, �� �� �������
void change_stroki(matrix *m,size_t x,size_t y);
//������������ �������� �� ������, �� �� �������
void change_stolb(matrix *m,size_t x,size_t y);
//��������� ������ �� �����
void mul_stroka(matrix *m,size_t x,double data);
//������� ������ �� �����
void div_stroka(matrix *m,size_t x,double data);
//����������� � ������ ������ ������ ���������� �� ������
void dve_stroki(matrix *m,size_t x,size_t y, double data);
//����� ������� (������������ ����� ������)
double norma(const matrix *m);
#endif // OTHER_H_INCLUDED
