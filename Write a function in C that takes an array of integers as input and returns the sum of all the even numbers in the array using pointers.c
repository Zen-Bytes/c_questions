//Write a function in C that takes an array of integers as input and returns the sum of all the even numbers in the array using pointers.

#include <stdio.h>

int sum_even_numbers(int *arr, int size) {
    int sum = 0;
    int i;
    for (i = 0; i < size; i++) {
        if (*(arr + i) % 2 == 0) { // Check if the number is even
            sum += *(arr + i); // Add the even number to the sum
        }
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int even_sum = sum_even_numbers(arr, size);
    printf("Sum of even numbers: %d\n", even_sum);

    return 0;
}
