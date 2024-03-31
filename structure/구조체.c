#include <stdio.h>
#include <string.h>

struct student {
    int age;
    char name[30];
};

int main() {
    struct student s1,s2,s3;

    s1.age = 24;
    strcpy(s1.name, "캇꼬꼬");
    printf("나이는 %d이고 이름은 %s입니다\n", s1.age, s1.name);

    s2.age = 22;
    strcpy(s2.name, "student's name");
    printf("나이는 %d이고 이름은 %s입니다\n", s2.age, s2.name);

    s3 = s2;
    printf("나이는 %d이고 이름은 %s입니다\n", s3.age, s3.name);
}