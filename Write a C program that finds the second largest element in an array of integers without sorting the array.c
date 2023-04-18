//Write a C program that finds the second largest element in an array of integers without sorting the array.

#include <stdio.h>

int findSecondLargest(int arr[], int n) {
    int largest = arr[0];      // Initialize largest and second largest
    int secondLargest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int secondLargest = findSecondLargest(arr, n);
    printf("The second largest element in the array is: %d\n", secondLargest);

    return 0;
}
