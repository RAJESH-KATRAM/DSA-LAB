#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *str) {
    strcpy(stack[++top], str);
}

char* pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            char operand[2];

            operand[0] = ch;
            operand[1] = '\0';

            push(operand);
        }

        else {
            char right[MAX];
            char left[MAX];
            char result[MAX];

            strcpy(right, pop());
            strcpy(left, pop());

            sprintf(result, "(%s%c%s)", left, ch, right);

            push(result);
        }
    }

    printf("Infix expression: %s\n", stack[top]);

    return 0;
}
