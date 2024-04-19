#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define STACK_SIZE 2
#define STACK1 0
#define STACK2 1

int stack_pointers[3];
int *stacks[3];

void initialize_stacks(int n) {
    for (int i = 0; i < 3; ++i) {
        stacks[i] = (int *)malloc(sizeof(int) * n);
        stack_pointers[i] = 0;
    }
}

void push_to_stack(int stack_index, int value) {
    stacks[stack_index][stack_pointers[stack_index]++] = value;
}

int pop_from_stack(int stack_index) {
    return stacks[stack_index][--stack_pointers[stack_index]];
}

void close_stacks() {
    for (int i = 0; i < 3; ++i)
        free(stacks[i]);
}

int is_stack_empty(int stack_index) {
    return stack_pointers[stack_index] == 0;
}

int stack_items_count(int stack_index) {
    return stack_pointers[stack_index];
}

int is_prime(int number) {
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

int find_next_prime(int number) {
    ++number;
    while (!is_prime(number))
        ++number;
    return number;
}

int main() {
    int n, q;
    int i, value;
    int input_stack, output_stack, prime;

    scanf("%d %d", &n, &q);

    int items[q];

    initialize_stacks(n);

    for (i = 0; i < n; ++i) {
        scanf("%d", &value);
        push_to_stack(STACK1, value);
    }

    input_stack = 0;
    output_stack = 1;
    prime = 2;

    for (i = 0; i < q; ++i) {

        while (!is_stack_empty(input_stack)) {
            int value = pop_from_stack(input_stack);
            if (value % prime == 0)
                push_to_stack(STACK_SIZE, value);
            else
                push_to_stack(output_stack, value);
        }

        items[i] = stack_items_count(STACK_SIZE);

        // SWAP stack pointers
        int temp = input_stack;
        input_stack = output_stack;
        output_stack = temp;

        prime = find_next_prime(prime);

        while (!is_stack_empty(STACK_SIZE)) {
            value = pop_from_stack(STACK_SIZE);
            printf("%d\n", value);
        }
    }

    while (!is_stack_empty(input_stack)) {
        value = pop_from_stack(input_stack);
        printf("%d\n", value);
    }

    close_stacks();

    return 0;
}
