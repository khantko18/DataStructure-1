#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

struct {
    float coef;
    int expon;
} terms[MAX_TERMS] = {{4.0, 3}, {3.0, 2}, {2.0, 1}, {1.0, 0}, {3.0, 2}, {2.0, 1}, {8.0, 0}};

int avail = 7;

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
    *Csp = avail;

    for (int i = As; i <= Ae; i++) {
        for (int j = Bs; j <= Be; j++) {
            float coef = terms[i].coef * terms[j].coef;
            int expon = terms[i].expon + terms[j].expon;
            attach(coef, expon);
        }
    }

    *Cep = avail - 1;
}

void print_poly(int s, int e) {
    for (int i = s; i < e; i++) {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main() {
    int c_start, c_end;

    printf("A = ");
    print_poly(0, 3);
    printf("B = ");
    print_poly(4, 6);

    poly_multiply(0, 3, 4, 6, &c_start, &c_end);

    printf("A * B = ");
    print_poly(c_start, c_end);

    return 0;
}
