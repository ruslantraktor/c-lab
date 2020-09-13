#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


int Factorial(int n) {
    if (n <= 1) return 1;
    return (n * Factorial(n - 1));
}

int Counting(int n, int m) {
    return Factorial(n) / (Factorial(m) * Factorial(n - m));
}

int main() {
    printf("%d * %d * %d = %d",Counting(10, 3),Counting(5, 3),Counting(7, 3), Counting(10, 3) * Counting(5, 3) * Counting(7, 3));
    return 0;
}
