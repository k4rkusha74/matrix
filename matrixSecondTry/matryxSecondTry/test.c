#include "matrix.h"

int main() {
    setlocale(LC_ALL, "Russian");
    // c�������
    Matrix A = create_matrix(3, 3, 1);
    Matrix B = create_matrix(3, 3, 2);

    // �������� �� ������
    if (A.data == NULL || B.data == NULL) {
        printf("������ ��� �������� �������\n");
        return 1;
    }

    // ��������� �������
    fill_random(&A, 1, 100);
    fill_random(&B, 50, 200);

    // ����� �� �����
    printf("������� A:\n");
    print_matrix(&A);
    printf("������� B:\n");
    print_matrix(&B);

    // ��������
    Matrix sum = add_matrices(&A, &B);
    if (sum.data == NULL) {
        printf("������ �������� ������\n");
    }
    else {
        printf("����� ������ A � B:\n");
        print_matrix(&sum);
        delete_matrix(&sum);
    }

    // ���������
    Matrix diff = subtract_matrices(&A, &B);
    if (diff.data == NULL) {
        printf("������ ��������� ������\n");
    }
    else {
        printf("�������� ������ A � B:\n");
        print_matrix(&diff);
        delete_matrix(&diff);
    }

    // ���������
    Matrix product = multiply_matrices(&A, &B);
    if (product.data == NULL) {
        printf("������ ��������� ������\n");
    }
    else {
        printf("������������ ������ A � B:\n");
        print_matrix(&product);
        delete_matrix(&product);
    }

    // ����������������
    Matrix transposed_A = transpose_matrix(&A);
    if (transposed_A.data == NULL) {
        printf("������ ���������������� �������\n");
    }
    else {
        printf("����������������� ������� A:\n");
        print_matrix(&transposed_A);
        delete_matrix(&transposed_A);
    }

    // �����������
    Matrix copied_B = copy_matrix(&B);
    if (copied_B.data == NULL) {
        printf("������ ����������� �������\n");
    }
    else {
        printf("����� ������� B:\n");
        print_matrix(&copied_B);
        delete_matrix(&copied_B);
    }

    // free
    delete_matrix(&A);
    delete_matrix(&B);

    return 0;
}