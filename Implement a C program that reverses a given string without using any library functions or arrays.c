Implement a C program that reverses a given string without using any library functions or arrays.

#include <stdio.h>

void reverseString(char *str) {
    // Find the length of the string
    int len = 0;
    char *temp = str;
    while (*temp != '\0') {
        len++;
        temp++;
    }

    // Swap characters from both ends of the string
    char *start = str;
    char *end = str + len - 1;
    char tempChar;
    while (start < end) {
        tempChar = *start;
        *start = *end;
        *end = tempChar;
        start++;
        end--;
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    int i = 0;
    while (input[i] != '\n') {
        i++;
    }
    input[i] = '\0';

    printf("Original string: %s\n", input);
    reverseString(input);
    printf("Reversed string: %s\n", input);

    return 0;
}
