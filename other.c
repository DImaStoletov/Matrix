#include "other.h"

matrix * matrix_T(matrix * m){
    if(m==NULL) return NULL;
    matrix *new_m= matrix_copy(m); if(!new_m) return NULL;
    if(matrix_realloc(m,m_h(m),m_w(m))==NULL) return NULL;
    for(size_t i=0;i<m_h(m);++i){
        for(size_t j=0;j<m_w(m);++j){
            *matrix_ptr(m,i,j)=*matrix_ptr(new_m,j,i);
        }
    }
    matrix_free(new_m);
    return m;
}

void change_stroki(matrix *m,size_t x,size_t y){
    x=x-1; y=y-1;
    if(m==NULL || x > m_h(m) || y > m_h(m)) return;
    double a;
    for(size_t i=0;i<m_w(m);++i){
        a=*matrix_ptr(m,x,i);
        *matrix_ptr(m,x,i)=*matrix_ptr(m,y,i);
        *matrix_ptr(m,y,i)=a;
    }
}

void change_stolb(matrix *m,size_t x,size_t y){
    x=x-1; y=y-1;
    if(m==NULL || x > m_w(m) || y > m_w(m)) return;
    double a;
    for(size_t i=0;i<m_h(m);++i){
        a=*matrix_ptr(m,i,x);
        *matrix_ptr(m,i,x)=*matrix_ptr(m,i,y);
        *matrix_ptr(m,i,y)=a;
    }
}


void mul_stroka(matrix *m,size_t x,double data){
    x=x-1;
    if(m==NULL || x > m_h(m)) return;
    for(size_t i=0;i<m_w(m);++i){
        *matrix_ptr(m,x,i)*=data;
    }
}

void div_stroka(matrix *m,size_t x,double data){
    mul_stroka(m,x,1/data);
}

void dve_stroki(matrix *m,size_t x,size_t y, double data){
    x=x-1;y=y-1;
    if(m==NULL || x > m_h(m) || y > m_h(m)) return;
    for(size_t i=0;i<m_w(m);++i){
        *matrix_ptr(m,x,i)+=(*matrix_ptr(m,y,i)*data);
    }
}


double norma(const matrix *m){
    if(m==NULL) return -1;
    double sum, res=0;
    for(size_t i=0;i<m_h(m);++i){
        sum=0;
        for(size_t j=0;j<m_w(m);++j){
            sum += fabs(*matrix_cptr(m,i,j));
        }
        res = res > sum ? res : sum;
    }
    return res;
}

