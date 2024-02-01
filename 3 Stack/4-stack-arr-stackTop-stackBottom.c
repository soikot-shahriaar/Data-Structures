#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    return sp->arr[0];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the Stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Can not pop from the Stack.\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;

    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("Stack has been Created Successfully.\n");

    printf("Before push, Full: %d\n", isFull(sp));
    printf("Before push, Empty: %d\n", isEmpty(sp));

    // push values onto the stack
    push(sp, 111);
    push(sp, 112);
    push(sp, 113);
    push(sp, 114);
    push(sp, 115);
    push(sp, 116);
    push(sp, 117);
    push(sp, 118);
    push(sp, 119);
    push(sp, 122);
    push(sp, 222); // stack overflow

    printf("After push, Full: %d\n", isFull(sp));
    printf("After push, Empty: %d\n", isEmpty(sp));

    // pop values from the stack
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));

    // call functions, stackTop and stackBottom.
    printf("The topmost value of this stack is %d\n", stackTop(sp));
    printf("The bottommost value of this stack is %d\n", stackBottom(sp));

    // free the allocated memory
    free(sp->arr);
    free(sp);

    return 0;
}
/* Understanding Code:
1. Create an integer function stackTop, and pass the reference to the stack you created as a parameter. Just return the element at the index top of the array. And that’s it.

2. Create an integer function stackBottom, and pass the reference to the stack you created as a parameter. And then return the element at the index 0 of the array.
*/