#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

 Stack_t* stack = NULL;
 uint32 stack_ret ;
 uint32 maxSize;
 uint32 value;
 uint32 count_stack;

int main()
{

    StackStatus_t fun_status = STACK_NOK;
    uint16 n = 1 ;
    uint16 op = 0 ;

    printf("Notes : \n");
    printf("To Create The Stack Choose    0 \n");
    printf("To Push Element Choose        1 \n ");
    printf("To Pop  Element Choose       2 \n");
    printf("To Get Stack Top Choose       3 \n");
    printf("To Get Stack Count Choose     4 \n");
    printf("To Destroy The Stack Choose   5 \n");
    printf("********************************************************* \n");
    printf("Stack Status Values : \n"
           "STACK NOt OK        = 0 \n"
           "STACK OK            = 1 \n"
           "STACK FULL          = 2 \n "
           "STACK EMPTY        = 3 \n"
           "STACK NULL POINTER  = 4 \n") ;
    printf("********************************************************* \n");

    while(n)
    {
        printf("Please Enter The Operation You Want \n ");
        scanf("%d",&op);
        switch(op)
        {
            case 0:
            printf("please enter the size \n");
            scanf("%d",&maxSize);
            stack = CreateStack( maxSize , &fun_status);
            printf("%d \n",fun_status);
            if(fun_status==STACK_OK)
            {
                printf("Stack Has Been Created \n");
                break;
            }
            else
            {
                printf("Error!!!! \n");
                break;
            }

            case 1:

            printf("please enter the number \n");
            scanf("%d",&value);
            fun_status = PushStack (stack, &value);
            printf("function status is -> %d \n",fun_status);
            break ;

            case 2:

            stack_ret = PopStack( stack , &fun_status);
            printf("Data poped %d \n",stack_ret);
            break ;

            case 3:

            stack_ret = StackTop ( stack , &fun_status);
            printf("Data on Top %d \n",stack_ret);
            break ;

            case 4:

            fun_status = StackCount (stack , &count_stack);
            printf("function status is -> %d \n",fun_status);
            printf("stack count = %d \n", count_stack );
            break ;

            case 5:

            stack = DestroyStack (stack, &fun_status);
            break ;
            n=0;
            }
    }


    return 0;

    }



