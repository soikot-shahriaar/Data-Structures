#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 911;
    head->next = second;

    second->data = 912;
    second->next = third;

    third->data = 913;
    third->next = fourth;

    fourth->data = 914;
    fourth->next = head;

    linkedListTraversal(head);

    return 0;
}

/* Traversing the Circular Linked List:

Create a void function linkedListTraversal and pass the head pointer of the linked list to the function.

In the function, create a pointer ptr pointing to the head.

Run a do-while loop until ptr reaches the last node, and ptr-> next becomes head, i.e. ptr->next = head. And keep printing the data of each node.

So, this is how we traverse through a circular linked list. And do-while was the key to make it possible.
*/
