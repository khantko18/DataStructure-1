#include <stdio.h>
#include <stdlib.h>

struct Term {
    float coef;
    int expon;
};

struct Polynomial {
    int num_terms;
    struct Term *terms;
};

void input_polynomial(struct Polynomial *poly) {
    printf("다항식의 총 항의 수를 입력하시오? ");
    scanf("%d", &poly->num_terms);

    poly->terms = (struct Term *)malloc(poly->num_terms * sizeof(struct Term));

    printf("고차항 부터 차례로 계수와 지수를 입력하시오:\n");
    for (int i = 0; i < poly->num_terms; i++) {
        printf("[계수, 차수] ");
        scanf("%f %d", &poly->terms[i].coef, &poly->terms[i].expon);
    }
}

void print_polynomial(struct Polynomial poly) {
    printf("입력된 다항식은 다음과 같습니다: ");
    for (int i = 0; i < poly.num_terms - 1; i++) {
        printf("%dx^%d + ", (int)poly.terms[i].coef, poly.terms[i].expon);
    }
    printf("%dx^%d\n", (int)poly.terms[poly.num_terms - 1].coef, poly.terms[poly.num_terms - 1].expon);
}

struct Polynomial multiply_polynomials(struct Polynomial poly1, struct Polynomial poly2) {
    struct Polynomial result;
    result.num_terms = poly1.num_terms * poly2.num_terms;
    result.terms = (struct Term *)malloc(result.num_terms * sizeof(struct Term));

    int idx = 0;
    for (int i = 0; i < poly1.num_terms; i++) {
        for (int j = 0; j < poly2.num_terms; j++) {
            result.terms[idx].coef = poly1.terms[i].coef * poly2.terms[j].coef;
            result.terms[idx].expon = poly1.terms[i].expon + poly2.terms[j].expon;
            idx++;
        }
    }

    return result;
}

void free_polynomial(struct Polynomial *poly) {
    free(poly->terms);
}

int main() {
    struct Polynomial poly1, poly2, result;

    printf("첫 번째 다항식을 입력하세요:\n");
    input_polynomial(&poly1);
    print_polynomial(poly1);

    printf("\n두 번째 다항식을 입력하세요:\n");
    input_polynomial(&poly2);
    print_polynomial(poly2);

    result = multiply_polynomials(poly1, poly2);

    printf("\n두 다항식의 곱은 다음과 같습니다:\n");
    print_polynomial(result);

    free_polynomial(&poly1);
    free_polynomial(&poly2);
    free_polynomial(&result);
    return 0;
}
