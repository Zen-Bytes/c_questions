#include <stdio.h>

int main() {

    int n, i, j, flag = 1;

    int matrix[10][10];

    printf("Enter the size of the square matrix: ");

    scanf("%d", &n);

    // input the elements of the matrix

    printf("Enter the elements of the matrix:\n");

    for(i = 0; i < n; i++) {

        for(j = 0; j < n; j++) {

            scanf("%d", &matrix[i][j]);

        }

    }

    // check if the matrix is a lower triangle matrix

    for(i = 1; i < n; i++) {

        for(j = 0; j < i; j++) {

            if(matrix[i][j] != 0) {

                flag = 0;

                break;

            }

        }

    }

    if(flag == 1) {

        printf("The matrix is a lower triangle matrix.\n");

        return 0;

    }

    flag = 1;

    // check if the matrix is an upper triangle matrix

    for(i = 0; i < n - 1; i++) {

        for(j = i + 1; j < n; j++) {

            if(matrix[i][j] != 0) {

                flag = 0;

                break;

            }

        }

    }

    if(flag == 1) {

        printf("The matrix is an upper triangle matrix.\n");

        return 0;

    }

    printf("The matrix is neither a lower triangle matrix nor an upper triangle matrix.\n");

    return 0;

}
