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
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
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

// function to check if two characters are matching brackets
int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

// function to check if parentheses and brackets in an expression are matching
int parenthesisMatch(char *exp)
{
    // create and initialize the stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]); // push opening brackets onto the stack
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                free(sp->arr); // free the allocated memory before returning.
                free(sp);
                return 0; // if there's a closing bracket but no matching opening bracket, return 0 (not matching)
            }
            popped_ch = pop(sp); // pop and check if the popped bracket matches the current closing bracket
            if (!match(popped_ch, exp[i]))
            {
                free(sp->arr); // free the allocated memory before returning.
                free(sp);
                return 0; // if brackets don't match, return 0 (not matching)
            }
        }
    }

    if (isEmpty(sp))
    {
        free(sp->arr); // free the allocated memory before returning.
        free(sp);
        return 1; // If the stack is empty, all brackets are matched, so return 1 (matching)
    }
    else
    {
        free(sp->arr); // free the allocated memory before returning.
        free(sp);
        return 0; // if there are unmatched opening brackets left, return 0 (not matching)
    }
}

int main()
{
    char *exp = "[4-6]((8){(9-8)})";

    // check if parentheses and brackets in the expression are matching
    if (parenthesisMatch(exp))
    {
        printf("The Parentheses and Brackets are Matching");
    }
    else
    {
        printf("The Parentheses and Brackets are NOT Matching");
    }
    return 0;
}

/*Understanding Code:

1. We’ll copy the whole thing from our last code, from creating the function parenthesisMatch to the stack inside.

2. It is important to copy everything because a lot of things will remain the same. We make zero changes in the declaration of the stack and its members.

3. Run a loop starting from the beginning of the expression till it reaches EOE.

4. If the current character of the expression is an opening parenthesis, be it of any type, push it into the stack using the push operation.

5. Else if the current character is a closing parenthesis of any type, see if the stack is not empty, using isEmpty, and if it is, return 0 there itself, else pop the topmost character using pop operation and store it in another character variable named popped_ch declared globally.

6. Create an integer function, match which will get the characters, popped_ch, and the current character of the expression as two parameters. Inside this function, check if these two characters are the same. If they are the same, return 1, else 0.

6. If the match function returns 1, our pop operation is successful, and we can continue checking further characters; else, if it returns 0, end the program here itself and return 0 to the main.

7. And if things went well throughout, and in the end, if the stack becomes empty, return 1, else 0.
*/