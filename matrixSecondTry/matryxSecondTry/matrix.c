#include "matrix.h"


Matrix create_matrix(int rows, int cols, int value) {
    if (rows <= 0 || cols <= 0) {
        Matrix error_matrix = { .rows = -1, .cols = -1, .data = NULL };
        return error_matrix;
    }

    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        matrix.data[i] = (int*)calloc(cols, sizeof(int));

        if (!matrix.data[i]) {
            delete_matrix(&matrix);  
            Matrix error_matrix = { .rows = -1, .cols = -1, .data = NULL };
            return error_matrix;
        }

        for (int j = 0; j < cols; ++j) {
            matrix.data[i][j] = value;
        }
    }

    return matrix;
}

void fill_random(Matrix* matrix, int min_value, int max_value) {
    srand(time(NULL));

    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            matrix->data[i][j] = rand() % (max_value - min_value + 1) + min_value;
        }
    }
}

Matrix add_matrices(const Matrix* A, const Matrix* B) {
    if (A->rows != B->rows || A->cols != B->cols) {
        Matrix error_matrix = { .rows = -1, .cols = -1, .data = NULL };
        return error_matrix;
    }

    Matrix result = create_matrix(A->rows, A->cols, 0);

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->cols; ++j) {
            result.data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }

    return result;
}

Matrix subtract_matrices(const Matrix* A, const Matrix* B) {
    if (A->rows != B->rows || A->cols != B->cols) {
        Matrix error_matrix = { .rows = -1, .cols = -1, .data = NULL };
        return error_matrix;
    }

    Matrix result = create_matrix(A->rows, A->cols, 0);

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->cols; ++j) {
            result.data[i][j] = A->data[i][j] - B->data[i][j];
        }
    }

    return result;
}

Matrix multiply_matrices(const Matrix* A, const Matrix* B) {
    if (A->cols != B->rows) {
        Matrix error_matrix = { .rows = -1, .cols = -1, .data = NULL };
        return error_matrix;
    }

    Matrix result = create_matrix(A->rows, B->cols, 0);

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < B->cols; ++j) {
            for (int k = 0; k < A->cols; ++k) {
                result.data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }

    return result;
}

Matrix transpose_matrix(const Matrix* matrix) {
    Matrix result = create_matrix(matrix->cols, matrix->rows, 0);

    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            result.data[j][i] = matrix->data[i][j];
        }
    }

    return result;
}

void delete_matrix(Matrix* matrix) {
    if (matrix && matrix->data) {
        for (int i = 0; i < matrix->rows; ++i) {
            free(matrix->data[i]);
        }
        free(matrix->data);
        matrix->data = NULL;
        matrix->rows = 0;
        matrix->cols = 0;
    }
}

Matrix copy_matrix(const Matrix* matrix) {
    Matrix new_matrix = create_matrix(matrix->rows, matrix->cols, 0);

    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            new_matrix.data[i][j] = matrix->data[i][j];
        }
    }

    return new_matrix;
}

void print_matrix(const Matrix* matrix) {
    if (matrix->data == NULL) {
        printf("Ошибка: Матрица пустая.\n");
        return;
    }

    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}