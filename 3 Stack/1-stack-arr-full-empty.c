#include <stdio.h>
#include <stdlib.h>

// creating stack
struct stack
{
    int size;
    int top;
    int *arr;
};

// implementing isEmpty
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

// implementing isFull
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

int main()
{
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // check if stack is empty or not
    if(isEmpty(s)){
        printf("The stack is Empty");
    }
    else{
        printf("The stack is not Empty");
    }
    return 0;
}

/*
Understanding Code:
1. So, the first thing would be to create the struct Stack. Include three members, an integer variable to store the size of the stack, an integer variable to store the index of the topmost element, and an integer pointer to hold the address of the array.

2. In main, create a struct stack s, and assign a value 100(we can assign any value of your choice) to its size, -1 to its top, and reserve memory in heap using malloc for its pointer arr. Don’t forget to include <stdlib> .

3. We have one more method to declare these stacks. We can define a struct stack pointer s, and use the arrow operators to deal with their members. The advantage of this method is that we can pass these pointers as references into functions very conveniently.

4. Before we advance to pushing elements in this stack, there are a few conditions to deal with. We can only push an element in this stack if there is some space left or the top is not equal to the last index. Similarly, we can only pop an element from this stack if some element is stored or the top is not equal to -1.

5. So, let us first write functions to check whether these stacks are empty or full.

6. Create an integer function isEmpty, and pass the pointer to the stack as a parameter. In the function, check if the top is equal to -1. If yes, then it’s empty and returns 1; otherwise, return 0.

7. Create an integer function isFull, and pass the pointer to the stack as a parameter. In the function, check if the top is equal to (size-1). If yes, then it’s full and returns 1; otherwise, return 0.
*/