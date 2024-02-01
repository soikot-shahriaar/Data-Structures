#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue
struct queue
{
    int size; // Maximum size of the queue
    int f;    // Front index of the queue
    int r;    // Rear index of the queue
    int *arr; // Pointer to an array to store queue elements
};

// Function to check if the queue is empty
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1; // Return 1 if the front and rear pointers are the same, indicating the queue is empty
    }
    return 0; // Return 0 if the queue is not empty
}

// Function to check if the queue is full
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1; // Return 1 if the rear pointer is at the maximum size minus one, indicating the queue is full
    }
    return 0; // Return 0 if the queue is not full
}

// Function to enqueue an element into the queue
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("This Queue is Full\n"); // If the queue is full, print an error message
    }
    else
    {
        q->r++;                                // Increment the rear pointer
        q->arr[q->r] = val;                    // Add the value to the queue at the new rear position
        printf("Enqueued Element: %d\n", val); // Print the enqueued element
    }
}

// Function to dequeue an element from the queue
int dequeue(struct queue *q)
{
    int a = -1; // Initialize a variable to store the dequeued element (initialized to -1 by default)
    if (isEmpty(q))
    {
        printf("This Queue is Empty.\n"); // If the queue is empty, print an error message
    }
    else
    {
        q->f++;           // Increment the front pointer
        a = q->arr[q->f]; // Store the dequeued element in 'a'
    }
    return a; // Return the dequeued element (or -1 if the queue was empty)
}

int main()
{
    struct queue q;                              // Declare a queue 'q' of type struct queue
    q.size = 4;                                  // Set the maximum size of the queue to 4
    q.f = q.r = 0;                               // Initialize front and rear pointers to 0
    q.arr = (int *)malloc(q.size * sizeof(int)); // Allocate memory for the queue array

    // Enqueue a few elements
    enqueue(&q, 111);
    enqueue(&q, 222);
    enqueue(&q, 333);

    // Dequeue elements and print them
    printf("Dequeuing Element %d\n", dequeue(&q));
    printf("Dequeuing Element %d\n", dequeue(&q));
    printf("Dequeuing Element %d\n", dequeue(&q));

    // Enqueue a few more elements
    enqueue(&q, 444);

    return 0;
}

/* Understanding the Code:
1. First of all, start by creating a struct named queue, and define all of its four members. An integer variable size to store the size of the array, another integer variable f to store the front end index, and an integer variable r to store the index of the rear end. Then, define an integer pointer arr to store the address of the dynamically allocated array.

2. In main, declare a struct queue q, and initialize its instances. Declare some size of the array, let 100. Initialize both f and r with -1. And allocate memory in heap for arr using malloc. Don’t forget to include the header file <stdlib.h>.

3. Creating isEmpty:
Create an integer function isEmpty, and pass into it the pointer to the struct queue q, as the only parameter. Inside the function, check if the r element of the q is equal to the f element of the q. Intuitively speaking, the difference between the values of f & r is the size of the queue. And if they both are equal, the size is 0. Therefore, if they are equal, return 1, else return 0.

4. Creating isFull:
Create an integer function isFull, and pass into it the pointer to the struct queue q as the only parameter. In the function, check if the r element of struct queue q is equal to the (size element)-1. If it is, then there is no space left in the queue to insert elements anymore, hence return 1, else 0.

5. Creating Enqueue:
Create a void function enqueue, pass the pointer to the struct queue q, and the value to insert as parameters. First of all, check if the queue is full by calling the isFull function. If it returns 1, then print the condition of the queue overflow and return. Else, increase the r value of q using the arrow operator, and insert the new value at the index r of the array arr.

6. Creating Dequeue:
Create an integer function dequeue, and pass the pointer to the struct queue q, as the only parameter into it. In the function, first of all, check if the queue is already not empty by calling the isEmpty function. If it returns 1, then print the condition of the queue underflow and return. Else, increase the f value of q using the arrow operator, and store the value at the index f of the array in some integer variable a. Later, return a.
*/