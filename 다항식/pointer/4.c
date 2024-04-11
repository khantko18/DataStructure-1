#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int age;
    char name[50];
} student;

void swap(int *first, int *second) {
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

int sumOfArray(int *sptr, int *eptr) {
    int sum = 0;

    while (sptr <= eptr) {
        sum = sum + (*sptr);
        sptr++;
    }
    return sum;
}

void print_student(student s) {
    printf("age = %d , name = %s\n", s.age, s.name);
}

void print_student_list(student *sptr, int n) {
    student *eptr = sptr + n;
    while (sptr < eptr) {
        printf("Age = %d, name = %s\n", sptr->age, sptr->name);
        sptr++;
    }
}

int main() {
    int i = 10;
    int j = 20;
    int sum = 0;
    int *iptr;

    student s[30] = {{21, "name 1"}, {22, "name 2"}, {23, "name 3"}};

    student *stdptr;
    int noOfStd;

    printf("How many students?");
    scanf("%d", &noOfStd);

    stdptr = (student *)malloc(sizeof(student) * noOfStd);

    for (int i = 0; i < noOfStd; i++) {
        printf("Enter age for student %d: ", i + 1);
        scanf("%d", &stdptr[i].age);
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", stdptr[i].name);
    }

    int iArray[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    swap(&i, &j);

    printf("Sum of iArray = %d\n", sumOfArray(&iArray[0], &iArray[19]));
    printf("Variable i = %d, Variable j = %d\n", i, j);

    // Call print_student_list function to print the student list
    print_student_list(stdptr, noOfStd);

    free(stdptr); // free dynamically allocated memory

    return 0;
}
