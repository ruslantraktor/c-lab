#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define colCount 10

int maximal(int a, int b) {
    if (a > b) return a;
    return b;
}

int getMaximalAbsElement(int array[], int n) {
    int maxElementValue = array[0];
    for (int i = 0; i < n; ++i) {
        maxElementValue = maximal(abs(array[i]), abs(maxElementValue));
    }
    return maxElementValue;
}


int getSumAfterLastZeroElement(int array[], int n) {
    int sum = 0;
    for (int i = n-1; i >= 0 && array[i] != 0; --i) {
        sum += array[i];
    }
    return sum;
}

int main() {
    const int MAX = 100, MIN = -100;
    int array[colCount];
    srand((unsigned) time(NULL));
    for (int i = 0; i < colCount; ++i) {
        array[i] = MIN + rand() % (MAX - MIN + 1);
    }

    printf("\nSum of array after last zero element = %d", getSumAfterLastZeroElement(array, colCount));
    printf("\nMaximal abs element of the array = %d", getMaximalAbsElement(array, colCount));
    return 0;
}
