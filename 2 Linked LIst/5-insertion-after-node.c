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

// Function for Insertion after a given Node
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 101;
    head->next = second;

    second->data = 102;
    second->next = third;

    third->data = 103;
    third->next = NULL;

    printf("Linked List Before Insertion:\n");
    linkedListTraversal(head); // Traversal
    head = insertAfterNode(head, second, 111); // Insertion
    printf("Linked List After Insertion:\n");
    linkedListTraversal(head); // Traversal again
    return 0;
}

/*
Insertion after a given Node:

Here, we already have a struct Node* pointer to insert the new node just next to it.

Create a struct Node* function insertAfterNode which will return the pointer to the head.

Pass into this function, the head node, the previous node, and the data.

Create a new struct Node* pointer ptr, and assign it a new memory location in the heap.

Since we already have a struct Node* prevNode given as a parameter, use it as p we had in the previous functions.

Assign prevNode->next to the next member of the ptr structure using ptr-> next = prevNode->next, and the given data to its data member.

Break the connection between prevNode and prevNode->next by assigning prevNode->next the new pointer. That is, prevNode->next = ptr.

Return head.
*/