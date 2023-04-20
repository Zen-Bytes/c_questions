#include <stdio.h>

void check_input(char *ptr_char);

int main() {

    char ch;

    printf("Enter a character or number: ");

    scanf("%c", &ch);

    check_input(&ch);

    return 0;

}

void check_input(char *ptr_char) {

    if (*ptr_char >= '0' && *ptr_char <= '9') {

        printf("%c is a number.\n", *ptr_char);

    } else if (*ptr_char >= 'a' && *ptr_char <= 'z') {

        printf("%c is a lowercase letter.\n", *ptr_char);

    } else if (*ptr_char >= 'A' && *ptr_char <= 'Z') {

        printf("%c is an uppercase letter.\n", *ptr_char);

    } else {

        printf("%c is not a number or letter.\n", *ptr_char);

    }

}
