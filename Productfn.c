#include <stdio.h>

double findProduct(int n) {
    // If n is 0, return 1 as the product
    if (n == 0) {
        return 1;
    }
    double num;
    scanf("%lf", &num);
    return num * findProduct(n - 1);
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter %d floating-point numbers: ", n);
    double product = findProduct(n);
    printf("Product of %d numbers: %.2lf\n", n, product);
    return 0;
}
