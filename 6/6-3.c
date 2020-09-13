#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define colCount 10

int maximal(int a, int b) {
    if (a > b) return a;
    return b;
}

int getMaximalElement(int array[], int n) {
    int maxElementValue = array[0];
    for (int i = 0; i < n; ++i) {
        maxElementValue = maximal(array[i], maxElementValue);
    }
    return maxElementValue;
}

int minimal(int a, int b) {
    if (a < b) return a;
    return b;
}

int getMinimalElement(int array[], int n) {
    int minimalElementValue = array[0];
    for (int i = 0; i < n; ++i) {
        minimalElementValue = minimal(array[i], minimalElementValue);
    }
    return minimalElementValue;
}

int getSumMaximalElementAndMinimal(int array[], int n){
    return getMaximalElement(array, n) + getMinimalElement(array, n);
}

int main() {
    const int MAX = 100, MIN = -100;
    int array[colCount];
    srand((unsigned) time(NULL));
    for (int i = 0; i < colCount; ++i) {
        array[i] = MIN + rand() % (MAX - MIN + 1);
    }

    printf("\nSum  = %d", getSumMaximalElementAndMinimal(array, colCount));
    return 0;
}
