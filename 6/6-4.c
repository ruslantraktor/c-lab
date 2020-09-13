#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define colCount 10
#define rowCount 10

int maximal(int a, int b) {
    if (a > b) return a;
    return b;
}

int getMaximalElement(int array[rowCount][colCount], int rows, int columns) {
    int maxElement[] = {array[0], 0, 0};//value, coords: x, y
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            maxElement[0] = maximal(maxElement[0], array[i][j]);
            if (maxElement[0] == array[i][j]){
                maxElement[1] = i;
                maxElement[2] = j;
            }
        }
    }
    return maxElement[1];
}

int minimal(int a, int b) {
    if (a < b) return a;
    return b;
}

int getMinimalElement(int array[rowCount][colCount], int rows, int columns) {
    int minElement[] = {array[0], 0, 0};//value, coords: x, y
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            minElement[0] = minimal(minElement[0], array[j][i]);
            if (minElement[0] == array[i][j]){
                minElement[1] = i;
                minElement[2] = j;
            }
        }
    }
    return minElement[1];
}

int scalar(int array[rowCount][colCount], int rows, int verticalVector, int hVector){
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        sum += array[verticalVector][i] * array[hVector][i];
    }
    return sum;
}

int main() {
    const int MAX = 100, MIN = -100;
    int array[rowCount][colCount];
    srand((unsigned) time(NULL));
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            array[i][j] = MIN + rand() % (MAX - MIN + 1);
        }
    }

    printf("\nSum  = %d", scalar(array, rowCount, getMinimalElement(array, rowCount, colCount), getMaximalElement(array, rowCount, colCount)));
    return 0;
}
