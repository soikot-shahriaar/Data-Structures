#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // Creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

int main()
{
    /*
    // Constructing the root node
    struct node *p;
    p = (struct node *) malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // Constructing the second node
    struct node *p1;
    p1 = (struct node *) malloc(sizeof(struct node));
    p->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // Constructing the third node
    struct node *p2;
    p2 = (struct node *) malloc(sizeof(struct node));
    p->data = 4;
    p2->left = NULL;
    p2->right = NULL;
    */

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    return 0;
}

/* Understanding the Code:
1. The first thing would be to create a struct Node. Inside the structure, we have three embedded elements, first is an integer variable data to store the data of the node, second is a struct Node pointer called left to store the address of the left child node, and third is again a struct Node pointer called right to store the address of the right child node.

2. Our next job would be to create the root node. In main, create struct Node pointer p, and assign to it the memory in heap using malloc. Don’t forget to include the header file <malloc.h> or <stdlib.h> And then using the pointer operator →, assign some data to its data element and NULL to both the left and the right element of the struct Node p.

3. And now we can proceed to creating the further nodes. We have different ways to do that. First one is to copy the whole thing we did for the root node twice for both the children and name them p1 and p2. This will create three separate nodes p, p1 and p2. Then just link them together by changing the left element of p from NULL to the left node’s pointer p1 and the right element of p from NULL to the right node’s pointer p2.

4. But this is somewhere redundant and not considered a good practice as we are copying the whole thing again and again. So, we would create a dedicated function for creating a node.

5.Creating the createNode function:
Create a struct Node* function createNode, and pass the data for the node as the only parameter. Create a struct Node pointer n. Reserve a memory in heap for n using malloc. Basically, do the same thing we did above. Point the left and the right element of the struct n to NULL, and fill the data in the data element. And return the node pointer n we created. This would simply create a node, and we can now very easily link them as per our wish via main to the other nodes.
*/