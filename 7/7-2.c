#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define n 6

int minimal(int a, int b) {
    if (a < b) return a;
    return b;
}

int getMinimalValue(int *array, int colCount) {
    int minimalValue = 100;
    for (int i = 0; i < colCount; ++i) {
        if (array[i] > 0) {
            minimalValue = minimal(abs(*(array + i)), abs(minimalValue));
        }
    }
    return minimalValue;
}

int getProduct(int *array, int colCount, int value){
    int product = 1;
    for (int i = 0; i < colCount && array[i]!=value; ++i) {
        product *= array[i];
    }
    return product;
}

int getCountPositiveElements(int *array, int colCount){
    int count = 0;
    for (int i = 0; i < colCount; ++i) {
        if (array > 0) count++;
    }
    return count;
}

int main() {
    srand((unsigned) time(NULL));
    const int MAX = 100, MIN = -100;
    int array[n];
    for (int i = 0; i < n; ++i) {
        array[i] = MIN + rand() % (MAX - MIN + 1);
    }
    printf("\nAmount of additional elements to the array %d", getCountPositiveElements(array, n));
    printf("\nThe product of the elements of the array, located to the minimum modulo element %d", getProduct(array, n, getMinimalValue(array, n)));
    return 0;
}
