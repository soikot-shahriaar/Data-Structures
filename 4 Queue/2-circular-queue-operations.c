#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is Full.\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqueued Element: %d\n", val);
    }
}

int dequeue(struct circularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is Empty.");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue a few elements
    enqueue(&q, 111);
    enqueue(&q, 222);
    enqueue(&q, 333);

    // Dequeue elements and print them
    printf("Dequeuing Element %d\n", dequeue(&q));
    printf("Dequeuing Element %d\n", dequeue(&q));
    printf("Dequeuing Element %d\n", dequeue(&q));

    // Enqueue and Dequeue few more elements
    enqueue(&q, 444);
    printf("Dequeuing Element %d\n", dequeue(&q));
    enqueue(&q, 555);

    return 0;
}
/* Understanding the Code:
1. First of all, copy everything from the queue implementation program since things are more or less the same, and circular queues are just a variation of normal queues. So, we would just make subtle modifications and things will work well.

2. Now, since it was a queue, replace queues with circular queues. Start by changing the struct named queue to a struct named circularQueue, and all the four members remain the same as queue.

3. In main, we had declared a struct circularQueue q, and initialized its instances. Here is a subtle change, we don’t initialize circular queues’ f and r with -1, rather 0.

4. Modifying isEmpty:
If we remember, the condition for isEmpty remains the same for both queues and circular queues. So, no modifications are needed here. Leave this as well.

5. Modifying isFull:
Earlier, isFull checked if our rear has reached the limit of the array. And if it did, we returned the overflow statement. But now, the queue isn’t full until technically. So, just see if the index next to the rear becomes front or not. Use circular increment (modulus) to pursue any increment in a circular queue.
So, check if (r element of q) +1 is equal to the (f element of q). If it is, then there is no space left in the queue to insert anymore elements, hence return 1, else 0.

6. Modifying Enqueue:
In the function enqueue, first of all, check if the queue is full by calling the isFull function. If it returns 1, then print the condition of the queue overflow and return. Else, increase the r value of q circularly using the arrow operator and modulus, and insert the new value at the increased index r of the array arr.

7. Modifying Dequeue:
Earlier when we dequeued in a queue, we would simply increase the value of f by 1. We would now increase but circularly, and that would be it.
In the function dequeue, first, check whether the circular queue is already not empty by calling isEmpty. If it returns 1, then print the condition of the queue underflow and return. Else, increase the f value of q using the arrow operator circularly, and store the value at the index f of the array in some integer variable a. Later, return a.
*/