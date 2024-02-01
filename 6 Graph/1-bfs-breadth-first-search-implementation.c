#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is Full.\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is Empty.\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS Implementation
    int node;
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}

/* Understanding the Code:
1. The first thing we should do is, bring the implementation part of the queue from our previous code.

2. Initializing a Queue:
Next thing we should do is initialize a queue, and dynamically assign it a memory in heap using malloc and define its size, say 400. Mark both its front and rear at zeroth index.

3. BFS Implementation:
Before we start programming the BFS implementation of the graph, we should first define a graph. And out of all the methods we have studied to represent a graph, we will be using the adjacency matrix one to define our graph here.

4. Define an integer variable node which we will use to traverse the graph. Define another integer variable i which is the node we are currently at.  So, since we would be the default starting with any node of our choice, we would initialize it with node 1.

5. Now, define an integer array visited to store the status of a node (of size 7 here), and the values corresponding to a node is 0, if it is unvisited and 1, if it is visited. And since, no node is already visited when we first start, therefore we’ll fill this array with all zeros.

6. Create an adjacency matrix corresponding to the graph.

7. Next, we would print the source node we have chosen, here node 1. Also, mark this node visited, which means make the ith index of the visited array 1. And since we are now interested in exploring the nodes connected to this source node, we would first enqueue this node into the queue q we created in step 2.

8. Create a while loop, and make it run while our queue is not empty. Queue becoming empty is the condition where we finish our traversal. We use the utility function isEmpty for the same.
Inside this loop, pluck the top element of the queue using dequeue and store it in an integer variable node. Run another for loop using j as the iterator, and since the size of our graph is 7, we’ll make this loop run from 0 to 7.
Now, every time we find edges node & j connected (that is cell a[node][j] equal to 1) and the node j unvisited, we mark it visited, and enqueue this newly visited node j in the queue. We'll print these nodes while we visit them to determine the BFS traversal order of the graph.
This way we will explore all the nodes, and the queue will ultimately become empty.
*/