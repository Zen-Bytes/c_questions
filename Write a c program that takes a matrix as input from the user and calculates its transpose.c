//Write a c program that takes a matrix as input from the user and calculates its transpose.

#include <stdio.h>
void inputMatrix(int matrix[10][10], int rows, int columns) {
    printf("elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter element at row %d and column %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void displayMatrix(int matrix[10][10], int rows, int columns) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
// Transpose matrix
void transposeMatrix(int matrix[10][10], int rows, int columns) {
    int transpose[10][10]; 
    // Calculating transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    // Displaying transpose matrix
    printf("Transpose Matrix:\n");
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int matrix[10][10]; // Matrix to store input
    int rows, columns; // Rows and columns of the matrix
    printf("number of rows: ");
    scanf("%d", &rows);
    printf("number of columns: ");
    scanf("%d", &columns);

    inputMatrix(matrix, rows, columns);
    displayMatrix(matrix, rows, columns);
    transposeMatrix(matrix, rows, columns);

    return 0;
}
