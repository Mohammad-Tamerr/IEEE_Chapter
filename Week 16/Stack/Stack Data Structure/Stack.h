
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "Types.h"

typedef struct{
    uint32 *StackArray;
    uint32 ElementCount;
    uint32 StackMaxSize;
    sint32 StackTop;
}Stack_t;

typedef enum{
    STACK_NOK = 0,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_POINTER
}StackStatus_t;


Stack_t* CreateStack (uint32 maxSize, StackStatus_t *ret_status);
Stack_t* DestroyStack (Stack_t* stack_obj, StackStatus_t *ret_status);
StackStatus_t PushStack (Stack_t* stack_obj, uint32* itemPtr);
uint32 PopStack (Stack_t* stack_obj, StackStatus_t *ret_status);
uint32 StackTop (Stack_t* stack_obj, StackStatus_t *ret_status);
StackStatus_t StackCount (Stack_t* stack_obj, uint32 *stack_count);

#endif // STACK_H

