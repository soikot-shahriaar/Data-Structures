#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (A[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    // DFS Implementation
    DFS(0);
    return 0;
}

/* Understanding the Code:
1. Since we will be using functions to be able to use stacks directly, we don't really have to bring the implementation part of the stack from our previous code. Let’s jump to our DFS implementation directly.

2. Before we start programming the DFS implementation of the graph, we should first define a graph. And out of all the methods we have studied to represent a graph, we will be using the adjacency matrix one to define our graph here. And since we have already done this in our last code where we implemented the Breadth-First Search, we’ll bring the same graph here as well. This would save us a lot of time. So, basically, we got ourselves an adjacency matrix A[7][7] corresponding to the graph.

3. Now, define an integer array visited to store the status of a node (of size 7 here), and the values corresponding to a node is 0 if it is unvisited and 1 if it is visited. We will fill this array with all zeros since no node has already been visited when we start.

4. Creating function DFS:
Now, we wish to define a function that would carry the Depth First Search traversal of the graph for us. So, create a void function DFS which will have the node i we want to visit as the only parameter. Inside that function, since that node which the function received as the parameter is the one to be visited now, we would mark it visited and print it at the same time. 

5. Next step requires us to see all nodes connected directly to this node. Run a for loop of size 7 with an iterator j, since that is the number of nodes we have. If any of them is not visited and there is an edge in between i and j, we would recursively call DFS passing this node j. And that’s all. Trust our function and it will do things in its own way. Our job has finished.
*/