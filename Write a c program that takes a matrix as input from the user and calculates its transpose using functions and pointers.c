//Write a c program that takes a matrix as input from the user and calculates its transpose using functions and pointers.

#include <stdio.h>

// Function to read matrix from user
void readMatrix(int *matrix, int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", matrix + i * cols + j);
        }
    }
}

// Function to display matrix
void displayMatrix(int *matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

// Function to calculate transpose of a matrix
void transposeMatrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            // Swap elements across the main diagonal
            int temp = *(matrix + i * cols + j);
            *(matrix + i * cols + j) = *(matrix + j * cols + i);
            *(matrix + j * cols + i) = temp;
        }
    }
}

int main() {
    int rows, cols;

    // Input number of rows and columns for the matrix
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Allocate memory dynamically for the matrix
    int *matrix = (int *)malloc(rows * cols * sizeof(int));

    // Read matrix from user
    readMatrix(matrix, rows, cols);

    // Display original matrix
    printf("Original ");
    displayMatrix(matrix, rows, cols);

    // Calculate transpose of matrix
    transposeMatrix(matrix, rows, cols);

    // Display transposed matrix
    printf("Transposed ");
    displayMatrix(matrix, cols, rows);

    // Free dynamically allocated memory
    free(matrix);

    return 0;
}
