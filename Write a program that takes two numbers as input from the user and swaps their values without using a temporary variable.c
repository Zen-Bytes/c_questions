//Write a program that takes two numbers as input from the user and swaps their values without using a temporary variable.

//method 1
#include <stdio.h>

void swap(int *a, int *b) {
    // Performing bitwise XOR to swap values without using a temporary variable
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    int num1, num2;

    // Taking input from user
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);

    // Swapping values using the swap() function
    swap(&num1, &num2);

    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}


//method 2
#include <stdio.h>

void swapWithoutTemp(int *a, int *b) {
    *a = *a + *b;  // Adding both numbers and storing the sum in the first number
    *b = *a - *b;  // Subtracting the original second number from the sum to get the original first number
    *a = *a - *b;  // Subtracting the original first number from the sum to get the original second number
}

int main() {
    int num1, num2;

    // Input two numbers from the user
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Call the function to swap the numbers without a temporary variable
    swapWithoutTemp(&num1, &num2);

    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

