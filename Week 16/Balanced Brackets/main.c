#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct Stack {
    char elements[MAX_SIZE];
    int top;
} stack;

void push(char character) {
    if (stack.top < MAX_SIZE) {
        stack.elements[++stack.top] = character;
    }
}

char pop() {
    if (stack.top > -1) {
        return stack.elements[stack.top--];
    } else {
        return -1;
    }
}

int areParenthesesBalanced(char *str, int length) {
    char target, current;
    if (length % 2 != 0) {
        return 0;
    }
    for(int i = 0; i < length; i++) {
        if ((str[i]=='(') || (str[i]=='{') || (str[i]=='[')) {
            push(str[i]);
        } else {
            switch(str[i]) {
                case ')': target = '('; break;
                case '}': target = '{'; break;
                case ']': target = '['; break;
            }
            current = pop();
            if (current == -1 || current != target) {
                return 0;
            }
        }
    }
    return pop() == -1;
}

int main() {
    int testCases, length;
    char input[MAX_SIZE], character;
    scanf("%d\n", &testCases);
    for (int i = 0; i < testCases; i++) {
        stack.top = -1;
        length = 0;
        while ((character = getchar()) != EOF && character != '\n') {
            input[length] = character;
            length++;
        }
        printf("%s\n", areParenthesesBalanced(input, length) == 0 ? "NO" : "YES");
    }
    return 0;
}
