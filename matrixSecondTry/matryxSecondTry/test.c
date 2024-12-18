#include "matrix.h"

int main() {
    setlocale(LC_ALL, "Russian");
    // cоздание
    Matrix A = create_matrix(3, 3, 1);
    Matrix B = create_matrix(3, 3, 2);

    // проверка на ошибки
    if (A.data == NULL || B.data == NULL) {
        printf("Ошибка при создании матрицы\n");
        return 1;
    }

    // случайные матрицы
    fill_random(&A, 1, 100);
    fill_random(&B, 50, 200);

    // вывод на экран
    printf("Матрица A:\n");
    print_matrix(&A);
    printf("Матрица B:\n");
    print_matrix(&B);

    // сложение
    Matrix sum = add_matrices(&A, &B);
    if (sum.data == NULL) {
        printf("Ошибка сложения матриц\n");
    }
    else {
        printf("Сумма матриц A и B:\n");
        print_matrix(&sum);
        delete_matrix(&sum);
    }

    // вычитание
    Matrix diff = subtract_matrices(&A, &B);
    if (diff.data == NULL) {
        printf("Ошибка вычитания матриц\n");
    }
    else {
        printf("Разность матриц A и B:\n");
        print_matrix(&diff);
        delete_matrix(&diff);
    }

    // умножение
    Matrix product = multiply_matrices(&A, &B);
    if (product.data == NULL) {
        printf("Ошибка умножения матриц\n");
    }
    else {
        printf("Произведение матриц A и B:\n");
        print_matrix(&product);
        delete_matrix(&product);
    }

    // транспонирование
    Matrix transposed_A = transpose_matrix(&A);
    if (transposed_A.data == NULL) {
        printf("Ошибка транспонирования матрицы\n");
    }
    else {
        printf("Транспонированная матрица A:\n");
        print_matrix(&transposed_A);
        delete_matrix(&transposed_A);
    }

    // копирование
    Matrix copied_B = copy_matrix(&B);
    if (copied_B.data == NULL) {
        printf("Ошибка копирования матрицы\n");
    }
    else {
        printf("Копия матрицы B:\n");
        print_matrix(&copied_B);
        delete_matrix(&copied_B);
    }

    // free
    delete_matrix(&A);
    delete_matrix(&B);

    return 0;
}