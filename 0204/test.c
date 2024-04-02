#include <stdio.h>
#include <stdlib.h> // exit 함수를 사용하기 위해 포함

#define MAX_TERMS 101

struct {
    float coef;
    int expon;
} terms[MAX_TERMS];

int avail = 0;

void print_poly(int s, int e);
void poly_multiply(int As, int Ae, int Bs, int Be, int *Csp, int *Cep);
void attach(float coef, int expon);

int main() {
    int Cs, Ce;
    
    // 다항식 A와 B를 정의
    terms[0].coef = 4.0; terms[0].expon = 3;
    terms[1].coef = 3.0; terms[1].expon = 2;
    terms[2].coef = 2.0; terms[2].expon = 1;
    terms[3].coef = 1.0; terms[3].expon = 0;
    avail = 4; // 다항식 A의 항 개수

    printf("A = ");
    print_poly(0, 3);
    
    terms[4].coef = 3.0; terms[4].expon = 2;
    terms[5].coef = 2.0; terms[5].expon = 1;
    terms[6].coef = 8.0; terms[6].expon = 0;
    avail = 7; // 다항식 B의 항 개수

    printf("B = ");
    print_poly(4, 6);

    poly_multiply(0, 3, 4, 6, &Cs, &Ce);

    printf("Result: ");
    print_poly(Cs, Ce);
    
    return 0;
}

void attach(float coef, int expon) {
    if (avail >= MAX_TERMS) {
        fprintf(stderr, "Too many terms\n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail++;
}

void poly_multiply(int As, int Ae, int Bs, int Be, int *Csp, int *Cep) {
    int i, j;
    *Csp = avail; // 결과 다항식의 시작 지수
    for (i = As; i <= Ae; i++) {
        for (j = Bs; j <= Be; j++) {
            attach(terms[i].coef * terms[j].coef, terms[i].expon + terms[j].expon);
        }
    }
    *Cep = avail - 1; // 결과 다항식의 끝 지수
}

void print_poly(int s, int e) {
    int i;
    for (i = s; i < e; i++) {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}
