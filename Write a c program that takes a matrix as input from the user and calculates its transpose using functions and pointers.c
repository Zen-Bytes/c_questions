//Write a c program that takes a matrix as input from the user and calculates its transpose using functions and pointers.

#include <stdio.h>
void readMatrix(int *matrix, int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", matrix + i * cols + j);
        }
    }
}
void displayMatrix(int *matrix, int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}
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
    printf("number of rows: ");
    scanf("%d", &rows);
    printf("number of columns: ");
    scanf("%d", &cols);
    int *matrix = (int *)malloc(rows * cols * sizeof(int));
    readMatrix(matrix, rows, cols);
    printf("Original ");
    displayMatrix(matrix, rows, cols);
    transposeMatrix(matrix, rows, cols);
    printf("Transposed ");
    displayMatrix(matrix, cols, rows);
    free(matrix);
    return 0;
}
