#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


int Factorial(int n) {
    if (n <= 1) return 1;
    return (n * Factorial(n - 1));
}

double calc(int x) {
    if (x < 2) return 1;
    return Factorial(x) / pow(x, x) + calc(x - 1);
}

int main() {
    printf("%f", calc(10));
    return 0;
}
