//Write a c program that takes a matrix as input from the user and calculates its transpose.

#include <stdio.h>

// Function to input the matrix from the user
void inputMatrix(int matrix[10][10], int rows, int columns) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter element at row %d and column %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display the matrix
void displayMatrix(int matrix[10][10], int rows, int columns) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the transpose of the matrix
void transposeMatrix(int matrix[10][10], int rows, int columns) {
    int transpose[10][10]; // Transpose matrix

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

    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns of the matrix: ");
    scanf("%d", &columns);

    inputMatrix(matrix, rows, columns);
    displayMatrix(matrix, rows, columns);
    transposeMatrix(matrix, rows, columns);

    return 0;
}
