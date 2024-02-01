#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void doublyLinkedListTraversal(struct Node *head)
{
    struct Node *current = head;

    // Traverse forward
    printf("Forward traversal:\n");
    while (current != NULL)
    {
        printf("Element is %d\n", current->data);
        current = current->next;
    }

    // Traverse backward
    printf("Backward traversal:\n");
    current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    while (current != NULL)
    {
        printf("Element is %d\n", current->data);
        current = current->prev;
    }
}

int main()
{

    struct Node *head = NULL;

    // Create a doubly linked list
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node *)malloc(sizeof(struct Node));

    node1->data = 1;
    node1->prev = NULL;
    node1->next = node2;

    node2->data = 22;
    node2->prev = node1;
    node2->next = node3;

    node3->data = 333;
    node3->prev = node2;
    node3->next = NULL;

    head = node1;

    // Traverse the doubly linked list
    doublyLinkedListTraversal(head);

    return 0;
}

/*
The doublyLinkedListTraversal function is defined to traverse and print the elements of a doubly linked list. It takes the head of the list as an argument. The function follows these steps:

It initializes a current pointer to the head node.

It performs a forward traversal by using a while loop that continues until current becomes NULL. Inside the loop, it prints the data of the current node and moves to the next node by updating current to current->next.

After the forward traversal, it resets current to the head and performs a backward traversal by moving to the last node using another while loop and then printing the data of each node while moving backward using the prev pointers.
*/
