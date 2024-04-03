#include <stdio.h>
#include <stdlib.h> // Added for using exit()

#define MAX_TERMS 101

struct {
    float coef;
    int expon;
} terms[MAX_TERMS] = {{8.0, 3}, {7.0, 1}, {1.0, 0}, {10.0, 3}, {3.0, 2}, {1.0, 0}};

int avail = 6;

void attach(float coef, int expon)
{
    if (avail >= MAX_TERMS)
    {
        fprintf(stderr, "Too many terms\n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail++;
}

void poly_add(int As, int Ae, int Bs, int Be, int *Csp, int *Cep)
{
    *Csp = avail;

    while ((As <= Ae) && (Bs <= Be))
    {
        if (terms[As].expon > terms[Bs].expon)
        {
            attach(terms[As].coef, terms[As].expon);
            As++;
        }
        else if (terms[As].expon == terms[Bs].expon)
        {
            if ((terms[As].coef + terms[Bs].coef) != 0)
            {
                attach((terms[As].coef + terms[Bs].coef), terms[As].expon);
            }
            As++;
            Bs++;
        }
        else
        {
            attach(terms[Bs].coef, terms[Bs].expon);
            Bs++;
        }
    }

    for (; As <= Ae; As++)
        attach(terms[As].coef, terms[As].expon);

    for (; Bs <= Be; Bs++)
        attach(terms[Bs].coef, terms[Bs].expon);

    *Cep = avail - 1;
}

void print_poly(int s, int e)
{
    for (int i = s; i < e; i++)
    {
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1f", terms[e].coef);
    if (terms[e].expon != 0)
    {
        printf("x^%d", terms[e].expon);
    }
    printf("\n");
}

int main()
{
    int c_start, c_end;

    printf("A = ");
    print_poly(0, 2);
    printf("B = ");
    print_poly(3, 5);

    poly_add(0, 2, 3, 5, &c_start, &c_end);

    printf("A + B = ");
    print_poly(c_start, c_end);

    return 0;
}