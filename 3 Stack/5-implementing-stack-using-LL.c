#include<stdio.h>
#include<stdlib.h>
 
struct Node {
    int data;  // an integer variable to store data in the Node.
    struct Node* next; // a pointer to another Node structure, representing the next node in the sequence.
};

struct Node* top = NULL;  // initialize a global pointer 'top' to represent the top of the stack, initially set to NULL.

void linkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);  // print the data of each node in the linked list.
        ptr = ptr->next;
    }
}
 
int isEmpty(struct Node* top) {
    if (top == NULL) {
        return 1;  // if 'top' is NULL, the stack is empty, so return 1 (true).
    } else {
        return 0;  // otherwise, return 0 (false).
    }
}
 
int isFull(struct Node* top) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));  // attempt to allocate memory for a new node.
    if (p == NULL) {
        return 1;  // if allocation fails, assume the stack is full and return 1 (true).
    } else {
        return 0;  // if allocation succeeds, return 0 (false).
    }
}
 
struct Node* push(struct Node* top, int x) {
    if (isFull(top)) {
        printf("Stack Overflow\n");  // if isFull() returns true, print a stack overflow message.
    } else {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));  // allocate memory for a new node.
        n->data = x;  // set the data of the new node to the provided value 'x'.
        n->next = top;  // set the 'next' pointer of the new node to the current 'top'.
        top = n;  // update 'top' to point to the new node, effectively pushing 'x' onto the stack.
        return top;  // return the updated 'top' pointer.
    }
}
 
int pop(struct Node* tp) {
    if (isEmpty(tp)) {
        printf("Stack Underflow\n");  // if isEmpty() returns true, print a stack underflow message.
    } else {
        struct Node* n = tp;  // create a temporary pointer 'n' to the top node.
        top = (tp)->next;  // update 'top' to point to the next node, effectively popping the top element.
        int x = n->data;  // store the data of the popped node.
        free(n);  // free the memory of the popped node.
        return x;  // return the popped element.
    }
}

int peek(int position) {
    struct Node* ptr = top; // Initialize a pointer 'ptr' to the top of the stack.

    for (int i = 0; (i < position - 1 && ptr != NULL); i++) {
        // Iterate through the stack until 'i' reaches 'pos-1' or 'ptr' becomes NULL.
        // This loop is used to traverse the stack to the desired position.

        ptr = ptr->next; // Move 'ptr' to the next node in the stack.
    }
    if (ptr != NULL) {
        // If 'ptr' is not NULL after the loop, it means the desired position is within the stack bounds.

        return ptr->data; // Return the data stored in the node pointed to by 'ptr' (the value of the element at the specified position).
    } else {
        // If 'ptr' is NULL after the loop, it means that the desired position is out of bounds,
        // indicating that the stack doesn't have enough elements.

        return -1; // Return -1 as an indicator that the operation couldn't be performed due to an out-of-bounds position.
    }
}
 
int main() {
    top = push(top, 111);  // push elements onto the stack.
    top = push(top, 112);
    top = push(top, 113);
    top = push(top, 114);
    top = push(top, 115);
    top = push(top, 116);
    
    linkedListTraversal(top);  // print the elements of the stack.
 
    int element = pop(top);  // pop the top element.
    printf("Popped Element is %d\n", element);  // print the popped element.

    //call peek function in a loop, printing the whole array.
    for (int i = 1; i <= 4; i++)
    {
        printf("Value at Position %d is: %d\n", i, peek(i));
    }
    return 0;
}

/* Understanding the Code:
1. Create the structure for nodes. We’ll use struct in C, name its Node, and make two members of this struct; an integer variable to store the data, and a struct Node pointer to store the address of the next element.

2. First of all, we’ll create the isEmpty and the isFull functions.

3. isEmpty():
    Create an integer function isEmpty, and pass the pointer to the top node as the parameter. If this top node equals NULL, return 1, else 0.

4. isFull():
    Create an integer function isFull, and pass the pointer to the top node as the parameter.
    Create a new struct Node* pointer p, and assign it a new memory location in the heap. If this newly created node p is NULL, return 1, else 0.
    
    It's important to note that the isFull function may not behave correctly in a linked list-based stack implementation because linked lists can typically grow dynamically until memory is exhausted. Checking for memory allocation success as an indicator of the stack being full is not a common practice for stack implementations using linked lists. A more common approach is to check for memory allocation failures when creating new nodes.

5. push():
    Create a struct Node* function push which will return the pointer to the new top node.
    We’ll pass the current top pointer and the data to push in the stack, in the function.
    Check if the stack is already not full, if full, return the condition stack overflow.
    Create a new struct Node* pointer n, and assign it a new memory location in the heap.
    Assign top to the next member of the n structure using n-> next = top, and the given data to its data member.
    Return this pointer n, since this is our new top node.

6. pop():
    Create an integer function pop which will return the element we remove from the top.
    We’ll pass the reference of the current top pointer in the function. We are passing the reference this time, because we are not returning the updated top from the function.
    Check if the stack is already not empty, if empty, return the condition stack underflow.
    Create a new struct Node* pointer n, and make it point to the current top. Store the data of this node in an integer variable x.
    Assign top to the next member of the list, by top = top->next, because this is going to be our new top.
    Free the pointer n. And return x.

7. peek():
    Create an integer function peek, and pass the position you want to peek in as a parameter.
    Since we have made the stack pointer global, we should not use that pointer to traverse; otherwise, we will lose the pointer to the top node. Rather create a new struct Node pointer ptr and give it the value of top.
    Run a loop from 0 to pos-1, since we are already at the first position. 
    If our pointer reaches NULL at some point, we must have reached the last node, and the position asked was beyond the available positions, hence breaking the loop.
    If the current pointer found the position and it is not equal to NULL, return the data at that node, else -1.
*/