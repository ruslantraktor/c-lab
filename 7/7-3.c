#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define colCount 6
#define rowCount 5


int **sortMatrixArray(int **array, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            for (int k = 0; k < columns; ++k) {
                if (k + 1 != columns && array[i][k] < array[i][k + 1]) {
                    int tempValue = array[i][k];
                    array[i][k] = array[i][k + 1];
                    array[i][k + 1] = tempValue;
                }
            }
        }
    }
    return array;
}

int main() {
    const int low = -100, height = 100;
    int** pArray = (int**)malloc(rowCount * sizeof(int));
    for (int i = 0; i < rowCount; i++) {
        pArray[i] = (int*)malloc(colCount * sizeof(int));
    }
    srand((unsigned) time(0));
    for (int i = 0; i < rowCount; i++) {
        printf("\n");
        for (int j = 0; j < colCount; j++) {
            pArray[i][j] = low + rand() % (height - low + 1);
            printf("%d\t", pArray[i][j]);
        }
    }
    printf("\nSorted array:");
    int **newArray = sortMatrixArray(pArray, rowCount, colCount);
    for (int i = 0; i < rowCount; ++i) {
        printf("\n");
        for (int j = 0; j < colCount; ++j) {
            printf("%d\t", newArray[i][j]);
        }
    }
    return 0;
}
