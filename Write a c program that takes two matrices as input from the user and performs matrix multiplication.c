//Write a c program that takes two matrices as input from the user and performs matrix multiplication.

#include <stdio.h>

// Function to read matrix from user
void readMatrix(int matrix[10][10], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[10][10], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix multiplication
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

    // Input number of rows and columns for the first matrix
    printf("Enter number of rows for matrix1: ");
    scanf("%d", &rows1);
    printf("Enter number of columns for matrix1: ");
    scanf("%d", &cols1);

    // Input number of rows and columns for the second matrix
    printf("Enter number of rows for matrix2: ");
    scanf("%d", &rows2);
    printf("Enter number of columns for matrix2: ");
    scanf("%d", &cols2);

    // Check if matrix multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible. Number of columns in matrix1 must be equal to the number of rows in matrix2.\n");
        return 0;
    }

    // Read first matrix from user
    readMatrix(matrix1, rows1, cols1);

    // Read second matrix from user
    readMatrix(matrix2, rows2, cols2);

    // Display original matrices
    printf("Matrix1:\n");
    displayMatrix(matrix1, rows1, cols1);
    printf("Matrix2:\n");
    displayMatrix(matrix2, rows2, cols2);

    // Perform matrix multiplication
    multiplyMatrix(matrix1, matrix2, result, rows1, cols1, rows2, cols2);

    // Display result matrix
    printf("Result Matrix:\n");
    displayMatrix(result, rows1, cols2);

    return 0;
}
