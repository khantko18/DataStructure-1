#include <stdio.h>

void swap(int *first, int *second) {
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

int sumOfArray(int *sptr, int *eptr) {
    int sum = 0;

    while(sptr <= eptr) {
        sum = sum + (*sptr);
        sptr++;
    }
    return sum;
}
int main() {
    int i = 10;
    int j = 20;
    int sum = 0;
    int *iptr;

    int iArray[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    swap(&i, &j);

    /*
    for(int k = 0; k < 20; k++) {
        sum = sum + iArray[k];
    }
    */

    //for(iptr = iArray; iptr <= (iArray19); iptr++) same with below for loop
    /*
    for(iptr = &iArray[0]; iptr <= &iArray[19]; iptr++)
        sum = sum + (*iptr);
    */
    printf("Sum of iArray = %d\n", sumOfArray(&iArray[0], &iArray[19]));
    printf("Variable i = %d, Variable j = %d\n", i, j);
    return 0;
}
