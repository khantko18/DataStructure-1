#include <stdio.h>
#include <ctype.h>
#define MAX 100

typedef struct stacktype {
    char stack[MAX];
    int top;
} stacktype;

void init(stacktype* s) {
    s->top = -1;
}

int is_full(stacktype* s) {
    return (s->top == MAX - 1);
}

int is_empty(stacktype* s) {
    return (s->top == -1);
}

char pop(stacktype* s) {
    char out;
    out = s->stack[(s->top)--];
    return out;
}

void push(stacktype* s, char item) {
    s->stack[++(s->top)] = item;
}

int check_matching(char input_string[]) {
    stacktype s;
    int i = 0;
    init(&s);
    while (input_string[i] != '\0') {
        if (is_full(&s)) {
            printf("스택이 가득 찼습니다.");
            return 0;
        }
        if (isalpha(input_string[i])) {
            if ('A' <= input_string[i] && input_string[i] <= 'Z') {
                char c = input_string[i] + ('a' - 'A');
                push(&s, c);
            }
            else {
                push(&s, input_string[i]);
            }
        }
        i++;
    }
    i = 0;
    int j = 0;
    while (input_string[i + j] != '\0') {
        if (isalpha(input_string[i + j])) {
            if ('A' <= input_string[i + j] && input_string[i + j] <= 'Z') {
                char a = input_string[i] + ('a' - 'A');
                if (pop(&s) != a) return 0;
            }
            else {
                if (pop(&s) != input_string[i + j]) return 0;
            }
            i++;
        }
        else j++;
    }
    if (!is_empty(&s)) printf("검사가 제대로 이루어지지 않았습니다");
    return 1;
}

int main() {
    char input_string[MAX] = { '\0' };

    printf("문자열을 입력하시오>>");
    fgets(input_string, sizeof(input_string), stdin); // Use fgets instead of gets_s
    if (check_matching(input_string) == 1) printf("회문입니다.");
    else printf("회문이 아닙니다.");
}
