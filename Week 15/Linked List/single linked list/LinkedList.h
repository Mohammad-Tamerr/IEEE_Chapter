
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include "Types.h"

struct Node_t{

    struct Node_t *next_add ;
    uint32 node_value;

} ;

typedef enum {

    Linked_NOK = 0,
    Linked_OK,
    Linked_FULL,
    Linked_EMPTY

} Linked_Status_t ;

Linked_Status_t Insert_Node_At_Begining(struct Node_t **List_Head);
Linked_Status_t Insert_Node_At_End(struct Node_t **List_Head);
Linked_Status_t Insert_Node_After(struct Node_t *List_Head);
uint32 Delete_Node_At_Begining(struct Node_t **List_Head);
uint32 Delete_Node_After(struct Node_t **List_Head);
uint32 get_Length (struct Node_t *List_Head);
void Display_All_Nodes(struct Node_t *List_Head);

#endif // _LINKEDLIST_H
