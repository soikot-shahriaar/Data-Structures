#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Initialize front and rear pointers to NULL
struct Node *f = NULL;
struct Node *r = NULL;

// Function to traverse and print the linked list
void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the Elements of this Linked List\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to enqueue (add to the rear) an element in the queue
void enqueue(int val)
{
    // Allocate memory for a new node
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is Full");
    }
    else
    {
        // Set the data and next pointers for the new node
        n->data = val;
        n->next = NULL;

        // If the queue is empty, set both front and rear to the new node
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            // Otherwise, update the next pointer of the rear node
            // to point to the new node and update rear to the new node
            r->next = n;
            r = n;
        }
    }
}

// Function to dequeue (remove from the front) an element from the queue
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        // Update front to the next node and retrieve the data from the front node
        f = f->next;
        val = ptr->data;

        // Free the memory of the removed node
        free(ptr);
    }
    return val;
}

int main()
{
    // Initial traversal of the empty queue
    linkedListTraversal(f);

    // Dequeue an element (queue is empty)
    printf("Dequeuing Element %d\n", dequeue());

    // Enqueue four elements to the queue
    enqueue(111);
    enqueue(222);
    enqueue(333);
    enqueue(444);

    // Traversal of the queue after enqueuing
    linkedListTraversal(f);

    // Dequeue four elements and print their values
    printf("Dequeuing Element %d\n", dequeue());
    printf("Dequeuing Element %d\n", dequeue());
    printf("Dequeuing Element %d\n", dequeue());
    printf("Dequeuing Element %d\n", dequeue());

    return 0;
}

/* Understanding Code:
1. Create a struct Node with two of its members, one integer variable data to store the data, and another struct Node pointer next to store the address of the next node.

2. Globally, create two struct Node pointers f and r, which would be used to mark the front and the rear ends. Declaring globally helps us use them in functions.

3. Creating Enqueue:
Create a void function enqueue, and the value to enqueue is the only parameter since we have declared the pointers f and r globally. In the function, create a new struct Node pointer n, and assign its memory in heap dynamically using malloc. Don’t forget to include the header file<stdlib.h>. Then check if the queue is full or, in other words, if there is no space in the heap. And that can be done by checking if the new pointer n equals NULL. If it does, then print the condition of the queue overflow and return. Else, insert the val in the data member of n, and make this node point to NULL. If we recall, we discussed a special case, where we were inserting in the list for the first time, when both f and r equals NULL. For this case, make both f and r equal to n, and for all the other cases, just make the r point the new node n. Ultimately make r equal to n since n becomes our new rear end. And that would be all.

4. Creating Dequeue:
Create an integer function dequeue. And we have no parameters to pass. Create a struct Node pointer ptr to hold the node we will delete. Make ptr equal to f. In the function, check if the queue is already not empty by checking if our front f is NULL or not. If it is NULL, then print the condition of the queue underflow and return. Else, make f equal to the next node to f. Store the data of ptr in an integer variable val. We can now free the pointer ptr. And return val, which is the data of the node we deleted.
*/