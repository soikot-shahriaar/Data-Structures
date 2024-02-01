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

// Function for Insertion in Between
struct Node *insertInBetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
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
    linkedListTraversal(head);   // Traversal
    head = insertInBetween(head, 111, 1);  // Insertion
    printf("Linked List After Insertion:\n");
    linkedListTraversal(head);  // Traversal again
    return 0;
}

/*
Insertion in Between:

Create a struct Node* function insertInBetween which will return the pointer to the head.

We’ll pass the current head pointer and the data to insert and the index where it will get inserted, in the function.

Create a new struct Node* pointer ptr, and assign it a new memory location in the heap.

Create a new struct Node* pointer pointing to head, and run a loop until this pointer reaches the index, where we are inserting a new node.

Assign p->next to the next member of the ptr structure using ptr-> next = p->next, and the given data to its data member.

Break the connection between p and p->next by assigning p->next the new pointer. That is, p->next = ptr.

Return head.
 */