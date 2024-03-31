#include <stdio.h>
#include <string.h>

struct myData {
    int myNum;
    char myName[30];
};

int main() {
    struct myData s1;
    s1.myNum = 5792582;
    strcpy(s1.myName, "Khant Ko Ko");

    printf("My number is %d\n", s1.myNum);
    printf("My name is %s\n", s1.myName);
}