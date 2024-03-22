#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

 Linked_Status_t Insert_Node_At_Begining(struct Node_t **List_Head )
 {
    Linked_Status_t status = Linked_NOK ;
    struct Node_t *req_node = NULL ;
    req_node = (struct Node_t *) malloc(sizeof(struct Node_t));
    if(NULL !=req_node)
    {
        printf("Please Enter The Number You Want To Insert \n");
        scanf("%d",&req_node->node_value);
         if(NULL == *List_Head)
            {
                req_node->next_add = NULL ;
                *List_Head = req_node ;
            }
            else
            {
                req_node->next_add = *List_Head ;
                *List_Head = req_node ;
            }
            status = Linked_OK ;
    }
    else
    {
        status = Linked_NOK ;
    }

    return status ;
}

Linked_Status_t Insert_Node_At_End(struct Node_t **List_Head)
{
    Linked_Status_t status = Linked_NOK ;
    struct Node_t *req_node = NULL ;
    struct Node_t *Last_Node = NULL ;
    req_node = (struct Node_t *) malloc(sizeof(struct Node_t));
    if(NULL != req_node)
    {
        printf("Please Enter The Number You Want To Insert \n");
        scanf("%d",&req_node->node_value);
        req_node->next_add = NULL ;
         if(NULL == *List_Head)
            {
                *List_Head = req_node ;
                status = Linked_OK ;

            }
            else
            {
                Last_Node =  *List_Head ;
                while (Last_Node->next_add != NULL)
                {
                    Last_Node = Last_Node->next_add ;
                }
                Last_Node->next_add = req_node ;
                status = Linked_OK ;
            }
    }
    else {}
    return status ;
}

Linked_Status_t Insert_Node_After(struct Node_t *List_Head)
{
    Linked_Status_t status = Linked_NOK ;
    struct Node_t *req_node = NULL ;
    struct Node_t *node_counter = NULL ;
    uint32 ListLength = 0 ;
    uint32 node_pos = 0 ;
    uint32 list_counter = 1 ;


    printf("Enter The Position You Want To Insert After \n") ;
    scanf("%d", &node_pos ) ;
    if(0 == node_pos)
    {
        printf("Choose 1 To Insert node In The Begining \n") ;
        Linked_Status_t status = Linked_NOK ;
    }
    else
    {
        ListLength = get_Length(List_Head);
        if(node_pos > ListLength )
        {
            printf("Invalid Node Position -> List has ( %i ) Nodes \n", ListLength);
        }
        else
        {
            node_counter = List_Head ;
            req_node = (struct Node_t *) malloc(sizeof(struct Node_t)) ;
                while(list_counter < node_pos )
                {
                    list_counter ++ ;
                    node_counter = node_counter->next_add ;
                }
                    if(NULL != req_node)
                    {
                        printf("Please Enter The Number You Want To Insert \n") ;
                        scanf("%d",&req_node->node_value) ;
                        req_node->next_add = node_counter->next_add ;
                        node_counter ->next_add = req_node ;
                        status = Linked_OK ;
                    }

                    else
                    {
                        status = Linked_NOK ;
                    }
        }
    }

    return status ;
}

uint32 get_Length (struct Node_t *List_Head)
{
    struct Node_t *TempNode = List_Head;
    uint32 NodeCount = 0;

    while(TempNode != NULL){
        NodeCount++;
        TempNode = TempNode->next_add;
    }

    return NodeCount;
}

void Display_All_Nodes(struct Node_t *List_Head)
{
    struct Node_t *node = List_Head ;
     printf("Node Values : ");
    if(NULL == node){
        printf("List is empty !! \n");
    }
    else{
        while(node != NULL){
            printf("%i -> ", node->node_value);
            node = node->next_add;
        }
        if(NULL == node){
            printf("NULL \n");
        }
    }
}

 uint32 Delete_Node_At_Begining( struct Node_t **List_Head)
{
    uint32 Data_Deleted = 0;
    struct Node_t *node = NULL ;
    if(get_Length(List_Head))
    {
        node = *List_Head ;
        Data_Deleted = node->node_value ;
        *List_Head = node->next_add ;
        free(node);
    }
    else
    {
        printf("Linked List Is Empty !!! \n");
    }
    return Data_Deleted ;
}

uint32 Delete_Node_After(struct Node_t **List_Head)
{
    uint32 Data_Deleted = 0;
    uint32 Node_pos = 0;
    uint32 Node_counter = 1;
    struct Node_t *list_couter = *List_Head ;
    struct Node_t *node = *List_Head ;
    printf("Please Enter The Node You Want To Delete \n");
    scanf("%d",&Node_pos);
    if(0 == Node_pos)
    {
        printf("Error !!!! Nodes Start From 1 \n");
    }
    else
    {
        if(Node_pos > get_Length(List_Head))
        {
            printf("Invalid Node Position -> List has ( %i ) Nodes \n", get_Length(List_Head));
        }
        else
        {
            while(Node_counter < ( Node_pos - 1 ))
            {
                Node_counter++ ;
                list_couter = list_couter->next_add ;
            }
            node = list_couter->next_add ;
            Data_Deleted = node->node_value ;
            list_couter->next_add = node->next_add ;
            free(node);
        }
    }
    return Data_Deleted ;
}

