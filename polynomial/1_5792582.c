#include <stdio.h>
#define MAX_DEGREE 101

struct polynomial {
    int degree;
    float coef[MAX_DEGREE];
};

struct polynomial a = {3, {4, 3, 2, 1}};
struct polynomial b = {2, {3, 2, 8}};

void print_polynomial(struct polynomial p);
struct polynomial multiply_polynomial(struct polynomial A, struct polynomial B);

int main() {
    struct polynomial X;
    print_polynomial(a);
    print_polynomial(b);
    X = multiply_polynomial(a, b);
    printf("-----------------------------------------------------\n");
    print_polynomial(X);
    return 0;
}

struct polynomial multiply_polynomial(struct polynomial A, struct polynomial B) {
    struct polynomial C;
    C.degree = A.degree + B.degree;
    
    for (int i = 0; i <= C.degree; i++) {
        C.coef[i] = 0.0;
    }

    for (int i = 0; i <= A.degree; i++) {
        for (int j = 0; j <= B.degree; j++) {
            C.coef[i + j] += A.coef[i] * B.coef[j];
        }
    }

    return C;
}

void print_polynomial(struct polynomial p) {
    for (int i = p.degree; i > 0; i--) {
        if (p.coef[p.degree - i] != 0.0) {
            printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
        }
    }

    if (p.coef[p.degree] != 0.0) {
        printf("%3.1f\n", p.coef[p.degree]);
    } else {
        printf("\n");
    }
}