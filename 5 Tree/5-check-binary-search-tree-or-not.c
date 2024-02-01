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

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preOrder(p);
    // printf("\n");
    // postOrder(p);
    // printf("\n");
    inOrder(p);
    printf("\n");
    // printf("%d", isBST(p));
    if (isBST(p))
    {
        printf("This is a Binary Search Tree.");
    }
    else
    {
        printf("This is not a Binary Search Tree.");
    }
    return 0;
}
/* Understanding the Code:
1. Since we’ll create a binary search tree at first which is nothing but a binary tree only and we’ll use the InOrder traversal function as well, we’ll simply copy everything we did in our last code where we learned to create the function inOrder.

2. Create the binary search tree the createNode function.

3. Let’s now just create a function to check if the InOrder traversal of the binary tree is in ascending order or not.

4. Creating the function isBST:
Create an integer function isBST and pass the pointer to the root node of the tree we want to check as the only parameter. Inside the function, check if the pointer is not NULL, as we have been checking the whole time, and this is also considered as the base case for the recursion to stop. If it is NULL, we would simply return 1 since an empty tree is always a binary search tree. Else, this is a complex yet understandable part.

5. Create a static struct Node pointer prev initialised with NULL. This maintains the pointer to the parent node. And since the root node doesn't have any parent, we have initialized it with NULL and made it static.

6. Now, see if the left subtree is a Binary Search Tree or not, by calling it recursively. If it is not a BST, return 0 here itself. Else, see if the prev is not NULL otherwise this is the root node of the whole tree and we won't check this condition. If the prev node is not NULL and the current node, which is the root node of the current subtree, is smaller than or equal to the prev node, then we would return 0. Since this violates the increasing orderliness.

7. If it still passes all the if conditions we have structured above, we will store the current node in the prev and move it recursively to the right subtree. And this is nothing but a modified version of the InOrder Traversal.
*/