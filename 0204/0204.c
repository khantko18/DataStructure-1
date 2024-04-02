#include <stdio.h>
#include <stdlib.h> // Added for using exit()
#define MAX_TERMS 101

struct {
    float coef;
    int expon;
} terms[MAX_TERMS] = {{8.0, 3}, {7.0, 2}, {1.0, 0}, {10.0, 3}, {3.0, 2}, {1.0, 0}};

int avail = 6;

void print_poly(int s, int e);
void poly_add2(int As, int Ae, int Bs, int Be, int *Csp, int *Cep);
void attach(float coef, int expon);

int main() {
    int Cs, Ce;
    printf("A = ");
    print_poly(0, 2);
    printf("B = ");
    print_poly(3, 5);
    poly_add2(0, 2, 3, 5, &Cs, &Ce);
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

void poly_add2(int As, int Ae, int Bs, int Be, int *Csp, int *Cep) {
    int c_start = avail;
    while ((As <= Ae) && (Bs <= Be)) {
        if (terms[As].expon > terms[Bs].expon) {
            attach(terms[As].coef, terms[As].expon);
            As++;
        } else if (terms[As].expon == terms[Bs].expon) {
            attach(terms[As].coef + terms[Bs].coef, terms[As].expon);
            As++;
            Bs++;
        } else {
            attach(terms[Bs].coef, terms[Bs].expon);
            Bs++;
        }
    }
    for (; As <= Ae; As++) {
        attach(terms[As].coef, terms[As].expon);
        c_start++;
    }
    for (; Bs <= Be; Bs++) {
        attach(terms[Bs].coef, terms[Bs].expon);
        c_start++;
    }
    *Csp = avail - c_start;
    *Cep = avail - 1;
}

void print_poly(int s, int e) {
    for (int i = s; i < e; i++) {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}