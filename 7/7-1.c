#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define n 6

int minimal(int a, int b) {
    if (a < b) return a;
    return b;
}

int getMinimalValue(int *array, int colCount){
    int minimalValue = 100;
    for (int i = 0; i < colCount; ++i) {
        if (array[i] > 0){
            minimalValue = minimal(*(array + i), minimalValue);
        }
    }
    return minimalValue;
}

int * changeValues(int *array, int colCount, int value){
    int * newArray = array;
    for (int i = 0; i < colCount; ++i) {
        if (array[i] < 0){
            newArray[i] = value;
        }
    }
    return newArray;
}

int main() {
    int a[n] = {3, -63, 12, -33, 77, 22};
    int * newArray = changeValues(a, n, getMinimalValue(a, n));
    for (int i = 0; i < n; ++i) {
        printf("%d\t", newArray[i]);
    }
    return 0;
}
