#include <stdio.h>

int main() {
    int i = 10, j = 12, k = 13, l = 19, m = 21;

    int intArray[5][10] = {{10, 12, 13, 19, 21, 31}, 
                           {13, 45, 56}};
    printf("intArray 크기는 %d 입니다\n", sizeof(intArray));
    printf("정수형 변수의 크기는 %d 입니다\n",sizeof(i));
    printf("intArray 배열 변수에는 %d개의 정수를 저장할 수 있습니다\n", sizeof(intArray) / sizeof(int));

    printf("변수 j의 값은 %d입니다\n", j);
    i = 11;
    j = k;
    
    printf("배열 intArray의 2번째 값은 %d입니다\n", intArray[1]);
    printf("배열 intArray[1][2]의 값은 %d입니다\n", intArray[1][2]);

    intArray[1][2] = 11;
    printf("배열 intArray[1][2]의 값은 %d입니다\n", intArray[1][2]);
    
    printf("배열 intArray[1][3]의 값은 %d입니다\n", intArray[1][3]);
    intArray[1][3] = k;
    printf("배열 intArray[1][3]의 값은 %d입니다\n", intArray[1][3]);

    m = intArray[1][4];

}