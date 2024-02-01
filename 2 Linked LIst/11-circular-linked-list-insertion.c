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

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // p points to the last node of this circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
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

    printf("Circular Linked list Before Insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 999);

    printf("Circular Linked list after insertion\n");
    linkedListTraversal(head);
    return 0;
}

/*
Inserting into a Circular Linked List:

Create a struct Node* function insertAtFirst which will return the pointer to the new head.

We’ll pass the current head pointer and the data to insert at the beginning, in the function.

Create a new struct Node* pointer ptr, and assign it a new memory location in the heap. This is our new node pointer.

Create another struct node * pointer p pointing to the next of the head. p = head-> next.

Run a while loop until the p pointer reaches the end element and p-> next becomes the head.

Now, assign ptr to the next of p, i.e.p->next  = ptr. And head to  the next of ptr, i.e. ptr->next = head.

Now, the new head becomes ptr. head = ptr.

Return head.
*/
