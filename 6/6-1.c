#include <stdio.h>

int sign(int x) {
    if (x < 0)return -1;
    if (x == 0) return 0;
    if (x > 0) return 1;
}

int main() {
    printf("%d\t", sign(0));
    printf("%d\t", sign(-1));
    printf("%d\t", sign(1));
    return 0;
}
