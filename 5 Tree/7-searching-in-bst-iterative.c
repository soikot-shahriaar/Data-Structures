// Iteration is more intuitive because we are able to see what's exactly happening and how things end. Even so, recursion is considered a powerful tool.
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

struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
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

    struct node *n = searchIter(p, 6);
    if (n != NULL)
    {
        printf("Found: %d", n->data);
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}

/* Understanding the Code:
1. We have just copied everything from creating a node, to building a tree. It also featured all the traversal methods, and all the other functions. 

2. Let’s create a binary search tree using the createNode function. And without doing any further ado, we would move to creating the searchIter.

3. Creating the function searchIter:
Create a struct Node pointer function searchIter and pass into it the pointer to the root and the key us want to search as two of its parameters.

4. First of all, check if the root’s data itself is the key we were looking for. If the root data is equal to the key, we have found the key, and we’ll return the pointer to the root.

5. If we couldn’t find the key on the root, we’ll further see if our key is greater than or smaller than the root data. If it is smaller than the root data, we will make the root node pointer now point to the left child of the root, using the arrow operator. And if the key is greater than the root data, we’ll make the root node pointer point to the right child of the root.

6. And we’ll use a while loop to run steps 4 and 5 iteratively until our root becomes NULL, or we find the key and return from the function.

7. And in the end, if we couldn’t find the key after iterating through the tree, or the root we received in the starting itself was a NULL, we would return NULL.
*/