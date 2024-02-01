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

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot Insert %d, already in BST", key);
            return;
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
    struct node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value)
{

    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // searching for the node to be deleted
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // deletion strategy when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
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

    inOrder(p);
    printf("\n");
    deleteNode(p, 3);
    inOrder(p);

    return 0;
}

/* Understanding the Code:
1. We could just copy everything we did in the last code where we learnt the insertion operation in a binary search tree.

2. We can always create a binary search tree of our own, and check if it is a BST using the InOrder traversal, and see if it's in ascending order or not. We would rather go with the one we already had in the program. Now, let’s see the deleteNode.

3. Creating the deleteNode function:
So, the first thing we would like to know is whether deleting this new node is even possible or not. For that, create a struct Node pointer function deleteNode and pass the pointer to the root node, and the data of the node we want to delete as its parameters. We will call it value.

4. So, the next thing we would do is see whether our value is greater than or less than the root node’s data. If it’s less than the root node’s data, we’ll simply recursively call the function to its left subtree, and pass the same value into it. And if it's greater, we’ll do the same thing with the right subtree. So, this basically reduces our problem. We do this until we reach the node we want to delete, or to the NULL, signifying the node was not there in the tree.

5. So, the deletion strategy says, when we find the node we want to delete, if we remember what we learnt, we can substitute it with its InOrder predecessor or with its InOrder successor. And we prefer doing it here using the InOrder predecessor. So, the first thing we would do here is to find the InOrder predecessor of the root node we want to delete and store it in a struct node pointer iPre. We would have a separate function for this, named inOrderPredecessor which we’ll see later. Suppose it returns the pointer to the InOrder Predecessor of the root node.

6. Having received the pointer to the InOrder Predecessor of the root node, we just copy the data of that predecessor node to our root node. And call the deleteNode function recursively to the left subtree of the root node, and with the value of the InOrder predecessor’s data. Now, observe this carefully. Why did we choose the left subtree? Because the InOrder predecessor of a node always lies on the left subtree of the node. And since we have replaced our root node with its InOrder predecessor, we have to now delete it from the left subtree.

7. And since these functions are recursive, we would need a base condition, and if we could realize, this recursive deletion of the replacing nodes must stop when it reaches a leaf node. So, the base conditions are when our given root is NULL, here we simply return NULL or both it's left and the right subtree is NULL, this is where the node we want to delete is the leaf node, so we’ll simply free this node. And simply return the root node at the end.

8. Now, this deleteNode function would not simply work alone. We would need an inOrderPredecessor function we have used in the program.

9. Creating the inOrderPredecessor function:
Create a struct node pointer function inOrderPredecessor and pass into it the pointer to the root node we want to find the InOrder predecessor of as its parameter.

10. So, simply update root to its left subtree, and use a while loop to iterate through all the right subtree, until we reach a leaf node. This gives our InOrder predecessor of the given node. Here, return the root.
*/