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

// Deleting the element with a given value from the linked list
struct Node * deleteWIthValue(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
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

    third->data = 103;
    third->next = NULL;

    printf("Linked List Before Deletion:\n");
    linkedListTraversal(head);  // Traversal
    head = deleteWIthValue(head, 102); // Deletion
    printf("Linked List After Deletion:\n");
    linkedListTraversal(head); // Traversal again
    return 0;
}

/*
Deleting the element with a given value from the linked list :

Here, we already have a value that needs to be deleted from the list. The main thing is that we’ll delete only the first occurrence.

Create a struct Node* function deleteByValue which will return the pointer to the head.

Pass into this function the head node, the value which needs to be deleted.

Create a new struct Node* pointer p pointing to the head.

Create another struct Node* pointer q pointing to the next of head.

Run a while loop until the pointer q encounters the given value or the list finishes.

If it encounters the value, delete that node by making p point the next node, skipping the node q. And free q from memory.

And if the list just finishes, it means there was no such value in the list. Continue without doing anything.

Return head.
*/