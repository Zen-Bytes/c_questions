//Write a C program that takes a sentence as input from the user and converts it to title case without using ctype module

#include <stdio.h>

void toTitleCase(char *str) {
    int i;
    // Convert first letter of sentence to uppercase
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 'a' + 'A';
    }
    // Loop through the remaining characters
    for (i = 1; str[i] != '\0'; i++) {
        // Check if current character is a space
        if (str[i] == ' ') {
            // Convert next character to uppercase
            if (str[i + 1] >= 'a' && str[i + 1] <= 'z') {
                str[i + 1] = str[i + 1] - 'a' + 'A';
            }
        }
    }
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    toTitleCase(sentence);
    printf("Title case sentence: %s\n", sentence);
    return 0;
}
