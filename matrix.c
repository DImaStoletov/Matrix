#include "matrix.h"

matrix* matrix_alloc(size_t h,size_t w){
    matrix * a = malloc(sizeof(matrix));
    if (!a) return NULL;
    a->data = malloc(h*w*sizeof(double));
    if(!a->data){
        free(a);
        return NULL;
    }
    a->h=h; a->w = w;
    return a;
}

void matrix_free (matrix *m){
    free(m->data);
    free(m);
}

double * matrix_ptr (matrix *m, size_t i, size_t j){
    return m->data + m->w * i + j;
}

const double * matrix_cptr (const matrix *m, size_t i, size_t j){
    return m->data + m->w * i + j;
}

void matrix_set_zero (matrix *m){
    if(m==NULL) return;
    for(size_t i=0; i<m->h;++i){
        for(size_t j=0; j<m->w; ++j){
            *matrix_ptr(m,i,j)=0;
        }
    }
}


void matrix_set_id (matrix *m){
    if(m==NULL) return;
    for(size_t i=0; i<m->h;++i){
        for(size_t j=0; j<m->w; ++j){
            if(i==j) *matrix_ptr(m,i,j)=1;
            else *matrix_ptr(m,i,j)=0;
        }
    }
}


matrix * matrix_alloc_zero (size_t w, size_t h){
    matrix * a = matrix_alloc(w,h);
    if(a==NULL) return NULL;
    matrix_set_zero(a);
    return a;
}

matrix * matrix_alloc_id (size_t w, size_t h){
    matrix * a = matrix_alloc(w,h);
    if(a==NULL) return NULL;
    matrix_set_id(a);
    return a;
}

int matrix_assign (matrix *m1, const matrix *m2){
    if(m1->h != m2->h || m1->w != m2->w || m1==NULL || m2==NULL) return -1;
    for(size_t i=0; i<m1->h;++i){
        for(size_t j=0; j<m1->w; ++j){
            *matrix_ptr(m1,i,j)=*matrix_cptr(m2,i,j);
        }
    }
    return 0;
}

matrix * matrix_copy (const matrix *m){
    if(m==NULL) return NULL;
    matrix * a =matrix_alloc(m->w,m->h);
    if(matrix_assign(a,m)==-1) return NULL;
    else return a;
}

void vvod(matrix *m){
    if(m==NULL) return;
    printf("Введите матрицу размером %ux%u:\n", (unsigned int)m->h, (unsigned int)m->w);
    for (size_t i = 0; i < m->h; ++i) {
        for (size_t j = 0; j < m->w; ++j) {
            printf("Элемент [%u][%u]: ", (unsigned int)i, (unsigned int)j);
            scanf("%lf", matrix_ptr(m, i, j));
        }
    }
}

void vivod(const matrix *m){
    if(m==NULL) return;
    printf("Матрица размером %ux%u:\n", (unsigned int)m->h, (unsigned int)m->w);
    for (size_t i = 0; i < m->h; ++i) {
        for (size_t j = 0; j < m->w; ++j) {
            printf(*matrix_cptr(m,i,j) == (int)*matrix_cptr(m,i,j) ? "%-8.0lf " : "%-8.2lf ", *matrix_cptr(m,i,j));
        }
        printf("\n");
    }
}

matrix * matrix_realloc(matrix * m,size_t w, size_t h){
    if(m==NULL) return NULL;
    free(m->data);
    m->data = malloc(h*w*sizeof(double));
    if(!m->data){
        free(m);
        return NULL;
    }
    m->h=h; m->w = w;
    return m;
}







