#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


typedef struct Matrix {
    int rows;
    int cols;
    int** data;
} Matrix;


Matrix create_matrix(int rows, int cols, int value);
void fill_random(Matrix* matrix, int min_value, int max_value);
Matrix add_matrices(const Matrix* A, const Matrix* B);
Matrix subtract_matrices(const Matrix* A, const Matrix* B);
Matrix multiply_matrices(const Matrix* A, const Matrix* B);
Matrix transpose_matrix(const Matrix* matrix);
void delete_matrix(Matrix* matrix);
Matrix copy_matrix(const Matrix* matrix);
void print_matrix(const Matrix* matrix);

#endif