#include <stdio.h>
#include <stdlib.h> // Added for using exit()
#define MAX_TERMS 101

struct {
    float coef;
    int expon;
} terms[MAX_TERMS];

int avail = 0;

void print_poly(int s, int e);
void attach(float coef, int expon);
void poly_multiply(int As, int Ae, int Bs, int Be, int *Csp, int *Cep);

int main() {
    int Cs, Ce;

    attach(4.0, 3);
    attach(3.0, 2);
    attach(2.0, 1);
    attach(1.0, 0);

    attach(3.0, 2);
    attach(2.0, 1);
    attach(8.0, 0);

    printf("A = ");
    print_poly(0, 3);
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
    int i, j, k;
    float tempcoef;
    int tempexpon;

    for (i = 0; i < MAX_TERMS; i++) {
        terms[i].coef = 0.0;
        terms[i].expon = 0;
    }

    for (i = As; i <= Ae; i++) {
        for (j = Bs; j <= Be; j++) {
            tempcoef = terms[i].coef * terms[j].coef;
            tempexpon = terms[i].expon + terms[j].expon;
            attach(tempcoef, tempexpon);
        }
    }

    for (i = 0; i < avail - 1; i++) {
        for (k = i + 1; k < avail; k++) {
            if (terms[i].expon == terms[k].expon) {
                terms[i].coef += terms[k].coef;
                terms[k].coef = 0.0;
            }
        }
    }

    int count = 0;
    for (i = 0; i < avail; i++) {
        if (terms[i].coef != 0.0) {
            terms[count].coef = terms[i].coef;
            terms[count].expon = terms[i].expon;
            count++;
        }
    }

    *Csp = 0;
    *Cep = count - 1;
}

void print_poly(int s, int e) {
    for (int i = s; i < e; i++) {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}