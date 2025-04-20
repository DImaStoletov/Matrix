#include "arithmetic.h"

int matrix_add (matrix *m1, const matrix *m2){
    if(m1==NULL || m2==NULL || m1->h!=m2->h ||m1->w!=m2->w) return -1;
    for(size_t i=0; i<m1->h;++i){
        for(size_t j=0; j<m1->w; ++j){
            *matrix_ptr(m1,i,j)=*matrix_ptr(m1,i,j)+*matrix_cptr(m2,i,j);
        }
    }
    return 0;
}

int matrix_sub (matrix *m1, const matrix *m2){
    if(m1==NULL || m2==NULL || m1->h!=m2->h ||m1->w!=m2->w) return -1;
    for(size_t i=0; i<m1->h;++i){
        for(size_t j=0; j<m1->w; ++j){
            *matrix_ptr(m1,i,j)=*matrix_ptr(m1,i,j)-*matrix_cptr(m2,i,j);
        }
    }
    return 0;
}

void matrix_smul (matrix *m, double d){
    if(m==NULL) return;
    for(size_t i=0; i<m->h;++i){
        for(size_t j=0; j<m->w; ++j){
            *matrix_ptr(m,i,j)=*matrix_ptr(m,i,j) * d;
        }
    }
}

void matrix_sdiv (matrix *m, double d){
    if(m==NULL) return;
    matrix_smul(m,1/d);
}

int matrix_add2 (matrix *m, const matrix *m1, const matrix *m2){
    if(m == NULL || m1 == NULL || m2 == NULL || m->w != m1->w || m->h != m1->h || m->w != m2->w || m->h != m2->h) return -1;
    matrix_assign(m,m1);
    matrix_add(m,m2);
    return 0;
}

int matrix_sub2 (matrix *m, const matrix *m1, const matrix *m2){
    if(m == NULL || m1 == NULL || m2 == NULL || m->w != m1->w || m->h != m1->h || m->w != m2->w || m->h != m2->h) return -1;
    matrix_assign(m,m1);
    matrix_sub(m,m2);
    return 0;
}

int matrix_smul2 (matrix *m, const matrix *m1, double d){
    if(m == NULL || m1 == NULL  || m->w != m1->w || m->h != m1->h) return -1;
    matrix_assign(m,m1);
    matrix_smul(m,d);
    return 0;
}

int matrix_sdiv2 (matrix *m, const matrix *m1, double d){
    if(m == NULL || m1 == NULL  || m->w != m1->w || m->h != m1->h) return -1;
    matrix_assign(m,m1);
    matrix_sdiv(m,d);
    return 0;
}


