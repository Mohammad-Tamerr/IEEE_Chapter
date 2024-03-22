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

// Define the Node and List structures for a doubly linked list
typedef struct Node Node;
typedef struct List List;

struct Node {
    int value;
    Node* next;
    Node* previous;
};

struct List {
    Node* first;
    Node* last;
};

// Function prototypes for list operations
Node* create_node(int value);
void append_to_list(List** list, int value);
void display_list(Node* node, const char* delimiter, FILE* stream);
void delete_list(Node* node);

// Function to create a new Node
Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

// Function to append a node to the list
void append_to_list(List** list, int value) {
    Node* node = create_node(value);
    if (!(*list)->first) {
        (*list)->first = node;
    } else {
        (*list)->last->next = node;
        node->previous = (*list)->last;
    }
    (*list)->last = node;
}

// Function to display the list
void display_list(Node* node, const char* delimiter, FILE* stream) {
    while (node) {
        fprintf(stream, "%d", node->value);
        node = node->next;
        if (node) {
            fprintf(stream, "%s", delimiter);
        }
    }
}

// Function to free the memory allocated for the list
void delete_list(Node* node) {
    while (node) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}

// Sorted insert function
Node* insert_sorted(Node* head, int value) {
    Node* newNode = create_node(value);
    if (!head) return newNode;
    if (newNode->value <= head->value) {
        newNode->next = head;
        head->previous = newNode;
        return newNode;
    }

    Node* current = head;
    while (current->next && current->next->value < newNode->value) {
        current = current->next;
    }

    if (!current->next) {
        current->next = newNode;
        newNode->previous = current;
    } else {
        newNode->next = current->next;
        current->next->previous = newNode;
        current->next = newNode;
    }
    return head;
}

// Main function
int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* line = read_line();
    int t = strtol(line, NULL, 10);
    free(line);

    for (int t_itr = 0; t_itr < t; t_itr++) {
        List* list = (List*)malloc(sizeof(List));
        list->first = NULL;
        list->last = NULL;

        line = read_line();
        int count = strtol(line, NULL, 10);
        free(line);

        for (int i = 0; i < count; i++) {
            line = read_line();
            int item = strtol(line, NULL, 10);
            free(line);

            append_to_list(&list, item);
        }

        line = read_line();
        int value = strtol(line, NULL, 10);
        free(line);

        Node* result = insert_sorted(list->first, value);
        const char* sep = " ";
        display_list(result, sep, fptr);
        fprintf(fptr, "\n");

        delete_list(result);
    }

    fclose(fptr);
    return 0;
}

// Read line from stdin
char* read_line() {
    size_t allocated = 1024, length = 0;
    char* data = malloc(allocated);

    while (true) {
        char* cursor = data + length;
        if (!fgets(cursor, allocated - length, stdin)) break;

        length += strlen(cursor);
        if (length < allocated - 1 || data[length - 1] == '\n') break;

        allocated *= 2;
        data = realloc(data, allocated);
    }

    if (data[length - 1] == '\n') data[length - 1] = '\0';
    return realloc(data, length);
}
