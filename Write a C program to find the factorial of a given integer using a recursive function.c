//Write a C program to find the factorial of a given integer using a recursive function.

#include <stdio.h>

// Function to find the factorial of a number using recursion
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Check for negative input
    if (num < 0) {
        printf("Error: Factorial is not defined for negative integers.\n");
    } else {
        int result = factorial(num);
        printf("Factorial of %d is %d.\n", num, result);
    }

    return 0;
}
