#include "arithmetic.h"

int matrix_add (matrix *m1, const matrix *m2){
    if(m1==NULL || m2==NULL || m_h(m1)!=m_h(m2) ||m_w(m1)!=m_w(m2)) return -1;
    for(size_t i=0; i<m_h(m1);++i){
        for(size_t j=0; j<m_w(m1); ++j){
            *matrix_ptr(m1,i,j)=*matrix_ptr(m1,i,j)+*matrix_cptr(m2,i,j);
        }
    }
    return 0;
}

int matrix_sub (matrix *m1, const matrix *m2){
    if(m1==NULL || m2==NULL || m_h(m1)!=m_h(m2) ||m_w(m1)!=m_w(m2)) return -1;
    for(size_t i=0; i<m_h(m1);++i){
        for(size_t j=0; j<m_w(m1); ++j){
            *matrix_ptr(m1,i,j)=*matrix_ptr(m1,i,j)-*matrix_cptr(m2,i,j);
        }
    }
    return 0;
}

void matrix_smul (matrix *m, double d){
    if(m==NULL) return;
    for(size_t i=0; i<m_h(m);++i){
        for(size_t j=0; j<m_w(m); ++j){
            *matrix_ptr(m,i,j)=*matrix_ptr(m,i,j) * d;
        }
    }
}

void matrix_sdiv (matrix *m, double d){
    if(m==NULL) return;
    matrix_smul(m,1/d);
}

int matrix_add2 (matrix *m, const matrix *m1, const matrix *m2){
    if(m == NULL || m1 == NULL || m2 == NULL || m_w(m) != m_w(m1) || m_h(m) != m_h(m1) || m_w(m) != m_w(m2) || m_h(m) != m_h(m2)) return -1;
    matrix_assign(m,m1);
    matrix_add(m,m2);
    return 0;
}

int matrix_sub2 (matrix *m, const matrix *m1, const matrix *m2){
    if(m == NULL || m1 == NULL || m2 == NULL || m_w(m) != m_w(m1) || m_h(m) != m_h(m1) || m_w(m) != m_w(m2) || m_h(m) != m_h(m2)) return -1;
    matrix_assign(m,m1);
    matrix_sub(m,m2);
    return 0;
}

int matrix_smul2 (matrix *m, const matrix *m1, double d){
    if(m == NULL || m1 == NULL  || m_w(m) != m_w(m1) || m_h(m) != m_h(m1)) return -1;
    matrix_assign(m,m1);
    matrix_smul(m,d);
    return 0;
}

int matrix_sdiv2 (matrix *m, const matrix *m1, double d){
    if(m == NULL || m1 == NULL  || m_w(m) != m_w(m1) || m_h(m) != m_h(m1)) return -1;
    matrix_assign(m,m1);
    matrix_sdiv(m,d);
    return 0;
}

int matrix_mul(matrix *m1, const matrix *m2){
    if(m1==NULL || m2==NULL || m_h(m1) != m_w(m2)) return -1;
    matrix * new_m = matrix_alloc(m_h(m1),m_w(m1)); if(new_m==NULL) return -1;
    matrix_assign(new_m,m1);
    if(matrix_realloc(m1,m_w(m2),m_h(m1))==NULL) {matrix_free(new_m); return -1;}
    double sum=0;
    for(size_t i=0;i<m_h(m1);++i){
        for(size_t j=0;j<m_w(m2);++j){
            for(size_t z=0;z<m_w(new_m);++z){
                sum += *matrix_ptr(new_m,i,z) * *matrix_cptr(m2,z,j);
            }
            *matrix_ptr(m1,i,j)=sum;
            sum=0;
        }
    }
    matrix_free(new_m);
    return 0;
}

int matrix_mul2(matrix *m, const matrix *m1, const matrix *m2){
    if(m==NULL || m1==NULL || m2==NULL) return -1;
    if(matrix_realloc(m,m_w(m1),m_h(m1)) == NULL) return -1;
    matrix_assign(m,m1);
    matrix_mul(m,m2);
    return 0;
}
