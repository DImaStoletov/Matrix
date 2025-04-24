#include "exp+gauss.h"

int matrix_exp(matrix *m, const matrix *A, double eps){
    if (m == NULL || A == NULL || m_w(A) != m_h(A) || m_w(m) != m_w(A) || m_h(m) != m_h(A)) return -1;
    matrix *x = matrix_alloc(m_h(m),m_w(m));
    matrix *y = matrix_alloc(m_h(m),m_w(m));
    if (x == NULL || y == NULL) {matrix_free(x); matrix_free(y); return -1;}
    matrix_set_id(m);
    matrix_assign(x, A); //(A^1/1!)
    int k = 1;
    do {
        matrix_add(m, x); //res += A^k/k!
        matrix_mul2(y, x, A); //y=A^k / k * A
        matrix_assign(x, y); //x=A^k / k * A
        matrix_sdiv(x, ++k); //x=A^k / k * A / (k+1) => x = A^(k+1) / (k+1)!
    } while (norma(x) >= eps);
    matrix_free(x); matrix_free(y);
    return 0;
}


matrix* gauss(const matrix* A, const matrix* B) {
    if (A == NULL || B == NULL || m_w(A) != m_h(A) || m_h(A) != m_h(B) || m_w(B) != 1) return NULL;
    size_t n = m_h(A);

//  [A|B]
    matrix* aug = matrix_alloc(n, n + 1);
    if (aug == NULL) return NULL;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            *matrix_ptr(aug, i, j) = *matrix_cptr(A, i, j);
        }
        *matrix_ptr(aug, i, n) = *matrix_cptr(B, i, 0);
    }


//    Прямой ход метода Гаусса
    for (size_t k = 0; k < n; k++) {
        // Поиск максимального элемента в столбце
        size_t max_row = k;
        double max_val = fabs(*matrix_cptr(aug, k, k));

        for (size_t i = k + 1; i < n; i++) {
            double val = fabs(*matrix_cptr(aug, i, k));
            if (val > max_val) {
                max_val = val;
                max_row = i;
            }
        }

        // Перестановка строк если нужно
        if (max_row != k) change_stroki(aug,k+1,max_row+1);

        // Проверка на вырожденность
        if (fabs(*matrix_cptr(aug, k, k)) < ERROR) {
            matrix_free(aug);
            return NULL;
        }

        // Нормализация текущей строки
        double x = *matrix_cptr(aug, k, k);
        div_stroka(aug,k+1,x);

        // Исключение элементов ниже

        for (size_t i = k + 1; i < n; i++) {
            double factor = *matrix_cptr(aug, i, k);
            dve_stroki(aug,i+1,k+1,-factor);
        }
    }

    // Обратный ход
    matrix* X = matrix_alloc(n, 1);
    if (X == NULL) {
        matrix_free(aug);
        return NULL;
    }
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (size_t j = i + 1; j < n; j++) {
            sum += *matrix_cptr(aug, i, j) * *matrix_cptr(X, j, 0);
        }
        *matrix_ptr(X, i, 0) = *matrix_cptr(aug, i, n) - sum;
    }
    matrix_free(aug);
    return X;
}


