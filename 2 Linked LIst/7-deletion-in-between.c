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

// Deleting the element at a given index from the linked list
struct Node *deleteInBetween(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
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

    head->data = 101;
    head->next = second;

    second->data = 102;
    second->next = third;

    third->data = 103;    third->next = NULL;

    printf("Linked List Before Deletion:\n");
    linkedListTraversal(head);  // Traversal
    head = deleteInBetween(head, 1); // Deletion
    printf("Linked List After Deletion:\n");
    linkedListTraversal(head); // Traversal again
    return 0;
}

/*
Deleting a node in Between:

Create a struct Node* function deleteInBetween which will return the pointer to the head.

In the function, we'll pass the current head pointer and the index where the node is to be deleted.

Create a new struct Node* pointer p pointing to head.

Create a new struct Node* pointer q pointing to head->next, and run a loop until this pointer reaches the index, from where we are deleting the node.

Assign q->next to the next member of the p structure using p->next = q->next.

Free the pointer q, because it has zero connections with the list now and return the head.
*/