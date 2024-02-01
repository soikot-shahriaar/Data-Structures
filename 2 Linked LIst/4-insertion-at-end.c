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

// Function for Insertion at the End
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
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
    linkedListTraversal(head);     // Traversal
    head = insertAtEnd(head, 111); // Insertion
    printf("Linked List After Insertion:\n");
    linkedListTraversal(head); // Traversal again
    return 0;
}

/*
Insertion at the End:

Inserting at the end is very similar to inserting at any index. The difference holds in the limit of the while loop. Here we run a loop until the pointer reaches the end and points to NULL.

Assign NULL to the next member of the new ptr structure using ptr-> next = NULL, and the given data to its data member.

Break the connection between p and NULL by assigning p->next the new pointer. That is, p->next = ptr.

Return head.
 */