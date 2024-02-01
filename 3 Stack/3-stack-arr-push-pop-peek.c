#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

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

// function to peek at element in to the stack
int peek(struct stack *sp, int i)
{
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a Valid Position for the Stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayInd];
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

    // peek into this stack array and print all the elements using a loop.
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The Value at Position %d is %d\n", j, peek(sp, j));
    }

    // free the allocated memory
    free(sp->arr);
    free(sp);

    return 0;
}

/* Understanding Code:
1. Create an integer function peek, and pass the reference to the stack, and the position to peek in, as its parameters.

2. Inside the function, create an integer variable arrayInd which will store the index of the array to be returned. This is just (top-position +1). 

3. Before we return anything, we’ll check if the arrayInd is a valid index. If it’s less than 0, it is invalid and we report an error. Otherwise,we just return the element at the index, (top-position+1).
*/