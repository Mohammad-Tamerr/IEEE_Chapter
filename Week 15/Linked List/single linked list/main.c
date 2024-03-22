#include <stdio.h>
#include <stdlib.h>
#include"LinkedList.h"
#include "Types.h"

struct Node *ListHead = NULL;

int main()
{
    Linked_Status_t status = Linked_NOK ;
    uint8 UserChoice = 0;
    uint32 ListLength = 0;
    uint32 Data_Deleted = 0 ;


    printf("-> Hello to Single Linked List \n");
    while(1){
        printf("\n");
        printf("===============================\n");
        printf("-> 1) Insert_Node_At_Beginning \n");
        printf("-> 2) Insert_Node_At_End \n");
        printf("-> 3) Insert_Node_After \n");
        printf("-> 4) Delete_Node_At_Beginning \n");
        printf("-> 5) Delete_Node \n");
        printf("-> 6) Display_All_Nodes \n");
        printf("-> 7) Get_Length \n");
        printf("-> 8) Quit from application \n");
        printf("===============================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &UserChoice);

        switch(UserChoice){
            case 1:
                status = Insert_Node_At_Begining(&ListHead);
                printf(" status -> %d \n" ,status ) ;
            break;
            case 2:
                status = Insert_Node_At_End(&ListHead);
                printf(" status -> %d \n" ,status ) ;
            break;
            case 3:
                status = Insert_Node_After(ListHead);
                printf(" status -> %d \n" ,status ) ;
            break;
            case 4:
            Data_Deleted = Delete_Node_At_Begining(&ListHead);
            printf("Data Deleted -> %d \n",Data_Deleted);
            break;
            case 5:
            Data_Deleted = Delete_Node_After(&ListHead);
            printf("Data Deleted -> %d \n",Data_Deleted);
            break;
            case 6:
                Display_All_Nodes(ListHead);
            break;
            case 7:
                ListLength = get_Length(ListHead);
                printf("List Length : << %i >> Nodes\n", ListLength);
            break;
            case 8:
                printf("Quit from application \n");
                exit(1);
            break;
            default:
                printf("User Choice out of range !!\n");
            break;
        }
    }
    return 0;
}
