//Implement a C program that reverses a given string without using any library functions or arrays.

#include <stdio.h>

void reverseString(char *str) {
    // length of the string
    int len = 0;
    char *z = str;
    while (*z != '\0') {
        len++;
        z++;
    }
    //swapping characters
    char *start = str;
    char *end = str + len - 1;
    char zChar;
    while (start < end) {
        zChar = *start;
        *start = *end;
        *end = zChar;
        start++;
        end--;
    }
}
int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
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
