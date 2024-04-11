#include <stdio.h>

int main() {
    int i = 10;
    int j;
    int *iptr;

    //j = i;
    iptr = &i; //&는 위치를 가르키다.
    j = *iptr; //*는 포인터가 가지고 있는 값
    printf("Variable i = %d, Variable j = %d\n", i, j);
}
