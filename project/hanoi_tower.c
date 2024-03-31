#include <stdio.h>

<<<<<<< HEAD
void hanoi_tower(int n, char from, char temp, char to) {
    if (n == 1)
        printf("원판 1을 %c에서 %c로 옮긴다\n", from, to);
    else {
        hanoi_tower(n - 1, from, to, temp);
        printf("원판 %d를 %c에 %c로 옮긴다\n", n, from, to); 
        hanoi_tower(n - 1, temp, from, to);
=======
void hanoi_tower(int n, char from, char tmp, char to) {
    if (n == 1)
        printf("원판 1을 %c에서 %c로 옮긴다\n", from, to);
    else {
        hanoi_tower(n - 1, from, to, tmp);
        printf("원판 %d를 %c에서 %c로 옮긴다\n", n, from, to); 
        hanoi_tower(n - 1, tmp, from, to);
>>>>>>> 8ccce06646813e8c89cf5d68228c225cbf175387
    }
}

int main() {
<<<<<<< HEAD
    hanoi_tower(3 , 'A', 'B', 'C');
    return 0;
}
 
=======
    hanoi_tower(3, 'A', 'B', 'C');
    return 0;
}
>>>>>>> 8ccce06646813e8c89cf5d68228c225cbf175387
