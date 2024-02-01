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
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{

    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("PreOrder:  ");
    preOrder(p);
    printf("\n");
    printf("PostOrder: ");
    postOrder(p);
    return 0;
}

/* Understanding the Code:
1. First of all, we just copy the whole thing we did previously, the struct Node and the createNode function and everything.

2. Create all the five nodes, using the createNode function, and link them using the arrow operator and altering their left and right pointer element. This creates our tree. The next thing would be to create the postOrder function.

3. Creating the postOrder function:
Create a void function postOrder and pass the pointer to the root node of the tree we want to traverse as the only parameter. Inside the function, check if the pointer is not NULL, otherwise we wouldn't do anything. If it is not NULL, we would not directly print the data of the root since this time it's the last one to get visited.

4. So first, we simply call the same function recursively on the left subtree and then the right subtree using the left and the right elements of the root struct. Once called, recursively, the function now considers the left subtree as an individual tree and applies postorder on it, and the same goes for the right subtree.

5. After visiting them both, we just print the data element of the root node marking it visited. And we are done.
*/