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

// Function for Insertion at the Beginning
struct Node *insertBeginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
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
    linkedListTraversal(head);  // Traversal
    head = insertBeginning(head, 111); // Insertion
    printf("Linked List After Insertion:\n");
    linkedListTraversal(head); // Traversal again
    return 0;
}

/*
Insertion at the Beginning: (Easiest one)

Create a struct Node* function insertBeginning which will return the pointer to the new head.

We’ll pass the current head pointer and the data to insert at the beginning, in the function.

Create a new struct Node* pointer ptr, and assign it a new memory location in the heap.

Assign head to the next member of the ptr structure using ptr-> next = head, and the given data to its data member.

Return this pointer ptr.
*/