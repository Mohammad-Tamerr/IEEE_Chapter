#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_line();

struct ListNode {
    int value;
    struct ListNode* next;
};

struct LinkedList {
    struct ListNode* head;
    struct ListNode* tail;
};

struct ListNode* create_node(int value) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void append_to_list(struct LinkedList** list, int value) {
    struct ListNode* newNode = create_node(value);
    if (!(*list)->head) {
        (*list)->head = newNode;
    } else {
        (*list)->tail->next = newNode;
    }
    (*list)->tail = newNode;
}

void display_list(struct ListNode* node, const char* delimiter, FILE* stream) {
    while (node != NULL) {
        fprintf(stream, "%d", node->value);
        node = node->next;
        if (node) {
            fprintf(stream, "%s", delimiter);
        }
    }
}

void free_list(struct ListNode* node) {
    while (node) {
        struct ListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

// Function to check if the linked list has a cycle
bool detect_cycle(struct ListNode* head) {
    struct ListNode* current = head;
    for (int steps = 0; steps < 1000; steps++) {
        if (!current) {
            return false;
        }
        current = current->next;
    }
    return true;
}

int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* tests_str = read_line();
    int tests = strtol(tests_str, NULL, 10);

    for (int t = 0; t < tests; t++) {
        int index = strtol(read_line(), NULL, 10);

        struct LinkedList* list = malloc(sizeof(struct LinkedList));
        list->head = NULL;
        list->tail = NULL;

        int count = strtol(read_line(), NULL, 10);

        for (int i = 0; i < count; i++) {
            int item = strtol(read_line(), NULL, 10);
            append_to_list(&list, item);
        }

        struct ListNode* extra = create_node(-1);
        struct ListNode* temp = list->head;

        for (int i = 0; i < count; i++) {
            if (i == index) {
                extra = temp;
            }
            if (i != count - 1) {
                temp = temp->next;
            }
        }

        temp->next = extra;

        bool result = detect_cycle(list->head);

        fprintf(fptr, "%d\n", result);
    }

    fclose(fptr);
    return 0;
}

char* read_line() {
    size_t allocated_size = 1024;
    size_t length = 0;
    char* data = malloc(allocated_size);

    while (true) {
        char* cursor = data + length;
        if (!fgets(cursor, allocated_size - length, stdin)) {
            break;
        }

        length += strlen(cursor);

        if (length < allocated_size - 1 || data[length - 1] == '\n') {
            break;
        }

        allocated_size *= 2;
        data = realloc(data, allocated_size);
    }

    if (data[length - 1] == '\n') {
        data[length - 1] = '\0';
    }

    return realloc(data, length);
}
