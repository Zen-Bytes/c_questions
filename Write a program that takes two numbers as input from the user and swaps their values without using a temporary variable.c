//Write a program that takes two numbers as input from the user and swaps their values without using a temporary variable.

//method 1

#include <stdio.h>
void swap(int *a, int *b) {
    //xor method
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}


//method 2

#include <stdio.h>
void swapWithoutTemp(int *a, int *b) {
    *a = *a + *b;  
    *b = *a - *b;  
    *a = *a - *b;  
}
int main() {
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Before swapp: num1 = %d, num2 = %d\n", num1, num2);
    swapWithoutTemp(&num1, &num2);
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}

