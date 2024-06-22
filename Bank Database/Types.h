#ifndef TYPES_H
#define TYPES_H

typedef struct customer_r {
  char name[50];
  float balances;
  char account_number[50];
} customer;

typedef struct node {
  customer Cust;
  struct node *next;
} Node;

typedef struct Point {
  Node *head;
  int size;
} Point_t;

#define NULL    0

#endif // TYPES_H

