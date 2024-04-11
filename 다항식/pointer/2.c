#include <stdio.h>

void swap(int *first, int *second) {
    int temp;
    temp = *first;
    *first = *second;
}
int main() {
    int i = 10;
    int j = 20;
    int k = 30;
    int l = 40;

    swap(&i, &j);
    swap(&k, &l);

    printf("Variable i = %d, Variable j = %d\n", i, j);
    printf("Variable k = %d, Variable l = %d\n", k, l);
    return 0;
}
