#include <stdio.h>
#include <stdlib.h>

// define a structure to represent a stack
struct stack
{
    int size; // maximum size of the stack
    int top;  // index of the top element in the stack
    int *arr; // pointer to an integer array to store stack elements
};

// function to check if the stack is empty
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1) // if the top index is -1, the stack is empty
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to check if the stack is full
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1) // if top index is equal to (size - 1), the stack is full
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to push an element onto the stack
void push(struct stack *ptr, int val)
{
    if (isFull(ptr)) // check if the stack is full before pushing
    {
        printf("Stack Overflow! Cannot push %d to the Stack\n", val);
    }
    else
    {
        ptr->top++;               // increment the top index
        ptr->arr[ptr->top] = val; // assign the value 'val' to the top index in 'arr'
    }
}

// function to pop (remove and return) the top element from the stack
int pop(struct stack *ptr)
{
    if (isEmpty(ptr)) // check if the stack is empty before popping
    {
        printf("Stack Underflow! Can not pop from the Stack.\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top]; // get the value at the top index
        ptr->top--;                   // decrement the top index
        return val;                   // return the popped value
    }
}

int main()
{
    // create a stack pointer 'sp' and allocate memory for the stack structure
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10; // set the maximum size of the stack to 10
    sp->top = -1;  // initialize the top index to -1 (empty stack)

    // allocate memory for the integer array 'arr' to store stack elements
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("Stack has been Created Successfully.\n"); // print a success message

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
    push(sp, 122); // pushed 10 values
    push(sp, 222); // stack overflow since the size of the stack is 10

    printf("After push, Full: %d\n", isFull(sp));
    printf("After push, Empty: %d\n", isEmpty(sp));

    // pop values from the stack
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));

    // remember to free allocated memory when you're done using the stack
    free(sp->arr);
    free(sp);

    return 0;
}

/*
1. The first thing is to define a stack. Suppose we have the creating stack and declaring its fundamentals part done, then pushing an element requires you to first check if there is any space left in the stack.

2. Call the isFull function. If it’s full, then we cannot push anymore elements. This is the case of stack overflow. Otherwise, increase the variable top by 1 and insert the element at the index top of the stack.
*/

/* Understanding Code:
1. We can just construct a struct stack, with all its three members, size, to store the size of the array used to handle this stack, top, to store the index of the topmost element in the stack and arr, a pointer to store the address of the array used.

2. In the main, define a struct stack pointer sp, which will store the address of the stack. Since we are using malloc to reserve the memory in heap for this stack, don't forget to include the header file <stdlib.h>.

3. Initialize all the elements of the stack with some values.

4. Create the integer functions isFull and isEmpty. These functions are a must, while we use the push or the pop operations.

5. Create a void function push, and pass into it the address of the stack using the pointer sp and the value which is to be pushed.

6. Don’t forget to first check if our stack still has some space left to push elements. Use isFull function for that. If it returns 1, this is the case of stack overflow, otherwise, increase the top element of the stack by 1, and insert the value at this new top of the array.

7. Create another void function pop, and pass into it the same address of the stack using the pointer sp. This is the only parameter since the pop operation pops only the topmost element.

8. Don’t forget to first check if our stack still has some elements left to pop elements. Use isEmpty function for that. If it returns 1, this is the case of stack underflow, otherwise, just decrease the top element of stack by 1, and we are done. The next time we push an element, we’ll overwrite the present element at that index. So, that’s basically ignored and acts as if it got deleted.
*/