//Write a c program that takes two matrices as input from the user and performs matrix multiplication.

#include <stdio.h>
void readMatrix(int matrix[10][10], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void displayMatrix(int matrix[10][10], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void multiplyMatrix(int matrix1[10][10], int matrix2[10][10], int result[10][10], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
int main() {
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int rows1, cols1, rows2, cols2;
    // first matrix
    printf("Enter number of rows for matrix1: ");
    scanf("%d", &rows1);
    printf("Enter number of columns for matrix1: ");
    scanf("%d", &cols1);
    //second matrix
    printf("Enter number of rows for matrix2: ");
    scanf("%d", &rows2);
    printf("Enter number of columns for matrix2: ");
    scanf("%d", &cols2);
    //matrix multiplication condition
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible. Number of columns in matrix1 must be equal to the number of rows in matrix2.\n");
        return 0;
    }
    readMatrix(matrix1, rows1, cols1);
    readMatrix(matrix2, rows2, cols2);
    multiplyMatrix(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
    printf("Result Matrix:\n");
    displayMatrix(result, rows1, cols2);
    return 0;
}
