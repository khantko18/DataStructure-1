#include <stdio.h>

int Fibonacci_rec(int n);

int main() {
    int fibonacci = 0;
    fibonacci = Fibonacci_rec(6);
    printf("Fibonacci 6 = %d\n", fibonacci);
    return 0;
}

int Fibonacci_rec(int n) {
    printf("f(%d) ",n);
    if(n == 0) return 0;   
    else if (n == 1) return 1;
    else return(Fibonacci_rec(n-1) + Fibonacci_rec(n-2));
}