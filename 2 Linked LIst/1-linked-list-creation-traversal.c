#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function for Traversal
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 101;
    head->next = second;

    // Link second and third nodes
    second->data = 102;
    second->next = third;

    // Terminate the list at the third Node
    third->data = 103;
    third->next = NULL;

    // Traversal Function Call
    linkedListTraversal(head);
    return 0;
}

/* Understanding Code:

An element in a linked list is a struct Node. It is made to hold integer data and a pointer of data type struct Node*, as it has to point to another struct Node.

We will always create individual nodes and link them to the next node via the arrow operator ‘->’.

First, we’ll define a structure Node and create two of its members, an int variable data, to store the current node's value and a struct node* pointer variable next.

Now, we can move on to our main() and start creating these nodes. We’ll name the first node, head. Define a pointer to head node by struct node* head. And similarly for the other nodes. Request the memory location for each of these nodes from heap via malloc using the below snippet.

         // head = (struct Node *)malloc(sizeof(struct Node));

Link these nodes using the arrow operator and call the traversal function.

Create a void function linkedListTraversal and pass into it the pointer to the head node.

Run a while loop while the pointer doesn’t point to a NULL. And keep changing the pointer next each time we are done printing the data of the current node.
*/