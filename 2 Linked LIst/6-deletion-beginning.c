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

// Deleting the first element from the linked list
struct Node *deleteFromBeginning(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
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

    printf("Linked List Before Deletion:\n");
    linkedListTraversal(head); // Traversal
    head = deleteFromBeginning(head); // Deletion
    printf("After Deleting First Element:\n");
    linkedListTraversal(head); // Traversal again
    return 0;
}

/*
Deleting the First Element:

Create a struct Node* function deleteFromBeginning which will return the pointer to the new head after deleting the current head.

We’ll pass the current head pointer in the function. Create a new struct Node* pointer ptr, and make it point to the current head.

Assign head to the next member of the list, by head = head->next, because this is going to be the new head of the linked list.

Free the pointer ptr. And return the head.
*/