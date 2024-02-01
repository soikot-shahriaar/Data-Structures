#include <stdio.h>
#include <stdlib.h>

// define a structure for the stack
struct stack
{
    int size;
    int top;
    char *arr;
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

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// function to check if parentheses in an expression are matching
int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '('); // push an opening parenthesis onto the stack
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                // if we encounter a closing parenthesis and the stack is empty,
                // it means there is no matching opening parenthesis.
                // return 0 to indicate that the parentheses are not matching.
                free(sp->arr); // free the allocated memory before returning.
                free(sp);
                return 0;
            }
            pop(sp); // pop a matching opening parenthesis from the stack
        }
    }

    int result = isEmpty(sp); // check if the stack is empty
    free(sp->arr);            // free the allocated memory.
    free(sp);
    return result; // if the stack is empty, return 1 (matching), otherwise return 0 (not matching)
}

int main()
{
    char *exp = "((8)(*--$$9))";
    // check if stack is empty
    if (parenthesisMatch(exp))
    {
        printf("The Parenthesis is Matching");
    }
    else
    {
        printf("The Parenthesis is NOT Matching");
    }
    return 0;
}

/* Understanding Code:
1. Start by creating an integer function paranthesisMatch, and pass the reference to a character array(expression) exp in the function as a parameter. This function will return 1 if the parentheses are balanced and zero otherwise.

2. Inside that function, create a stack pointer sp. And initialize the size member to some big number, let it be 100. Initialize the top to -1, and assign the array pointer a memory location in the heap. We have the freedom to choose any data structure we want to implement this stack.

3. So, it would be better if we  just copy everything of stack implementation because it will more or less remain the same for that part. We’ll use the array one.

4. Change the datatype of the array from integer to char. Accordingly, change everything from integer to char. And arr to exp.

5. Run a loop starting from the beginning of the expression till it reaches EOE.

6. If the current character of the expression is an opening parenthesis, push it into the stack using the push operation.

7. Else if the current character is a closing parenthesis, see if the stack is not empty, using isEmpty, and if it is, return 0 there itself, else pop the topmost character using pop operation.

8. In the end, if the stack becomes empty, return 1, else 0.

9. In the main, define a random character array expression and just passing this expression to parenthesisMatch would do our job.
*/