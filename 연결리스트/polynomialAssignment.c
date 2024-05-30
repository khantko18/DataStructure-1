#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Term {
    int coeff;
    int exp;
    struct Term* next;
} Term;

Term* createTerm(int coeff, int exp) {
    Term* term = (Term*)malloc(sizeof(Term));
    term->coeff = coeff;
    term->exp = exp;
    term->next = NULL;
    return term;
}

void addTerm(Term** poly, int coeff, int exp) {
    if (coeff == 0) return;
    
    Term* newTerm = createTerm(coeff, exp);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term* current = *poly;
        Term* prev = NULL;
        while (current != NULL && current->exp > exp) {
            prev = current;
            current = current->next;
        }
        if (current != NULL && current->exp == exp) {
            current->coeff += coeff;
            if (current->coeff == 0) {
                if (prev == NULL) {
                    *poly = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
            }
            free(newTerm);
        } else {
            if (prev == NULL) {
                newTerm->next = *poly;
                *poly = newTerm;
            } else {
                newTerm->next = current;
                prev->next = newTerm;
            }
        }
    }
}

void parsePolynomial(const char* polyStr, Term** poly) {
    int i = 0;
    int len = strlen(polyStr);
    while (i < len) {
        int sign = 1;
        if (polyStr[i] == '-') {
            sign = -1;
            i++;
        } else if (polyStr[i] == '+') {
            i++;
        }
        
        int coeff = 0;
        while (i < len && isdigit(polyStr[i])) {
            coeff = coeff * 10 + (polyStr[i] - '0');
            i++;
        }
        if (coeff == 0) coeff = 1;
        coeff *= sign;
        
        int exp = 0;
        if (i < len && polyStr[i] == 'x') {
            i++;
            if (i < len && polyStr[i] == '^') {
                i++;
                while (i < len && isdigit(polyStr[i])) {
                    exp = exp * 10 + (polyStr[i] - '0');
                    i++;
                }
            } else {
                exp = 1;
            }
        }
        
        addTerm(poly, coeff, exp);
    }
}

void printPolynomial(Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    Term* current = poly;
    while (current != NULL) {
        if (current->coeff > 0 && current != poly) {
            printf("+");
        }
        if (current->exp == 0) {
            printf("%d", current->coeff);
        } else if (current->exp == 1) {
            if (current->coeff == 1) {
                printf("x");
            } else if (current->coeff == -1) {
                printf("-x");
            } else {
                printf("%dx", current->coeff);
            }
        } else {
            if (current->coeff == 1) {
                printf("x^%d", current->exp);
            } else if (current->coeff == -1) {
                printf("-x^%d", current->exp);
            } else {
                printf("%dx^%d", current->coeff, current->exp);
            }
        }
        current = current->next;
    }
    printf("\n");
}

void freePolynomial(Term* poly) {
    Term* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    char poly1Str[100], poly2Str[100];
    printf("첫 번째 다항식을 입력하세요: ");
    scanf("%s", poly1Str);
    printf("두 번째 다항식을 입력하세요: ");
    scanf("%s", poly2Str);
    
    Term* poly1 = NULL;
    Term* poly2 = NULL;
    
    parsePolynomial(poly1Str, &poly1);
    parsePolynomial(poly2Str, &poly2);
    
    Term* result = NULL;
    
    Term* current = poly1;
    while (current != NULL) {
        addTerm(&result, current->coeff, current->exp);
        current = current->next;
    }
    
    current = poly2;
    while (current != NULL) {
        addTerm(&result, current->coeff, current->exp);
        current = current->next;
    }
    
    printf("두 다항식의 합은: ");
    printPolynomial(result);
    
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);
    
    return 0;
}
