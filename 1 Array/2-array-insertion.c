#include <stdio.h>

// Traversal
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insertion
int insertion(int arr[], int capacity, int size, int element, int index)
{

    if (size >= capacity)
    {
        return -1;
    }
    // Shift elements to right to make space for the new element
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    // Inserting the new element at the specified index
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {11, 22, 33, 44, 55};
    int size = 5, element = 77, index = 3;
    printf("Before Insertion: ");
    display(arr, size);

    int result = insertion(arr, 100, size, element, index);
    if (result == 1)
    {
        size++;
        printf("After  Insertion: ");
        display(arr, size);
    }
    else
    {
        printf("Insertion Failed. Array is Full.\n");
    }

    return 0;
}

/*
// for (int i = size - 1; i >= index; i--)
The loop starts from the last index of the array (size - 1) and iterates until it reaches the specified index (index). i-- decrements the loop variable i in each iteration.

// arr[i + 1] = arr[i];
In each iteration of the loop, the element at index i is moved to the next position. This process effectively shifts all elements from the specified index (index) to the end of the array one position to the right.

// arr[index] = element;
After completing the loop, there is now space at the specified index (index) for the new element.
The line inserts the new element (element) at the desired index.
*/

/* Understanding Code:
1. We will start by declaring an array arr of length 100. Initialize this array with 5 elements. This will be our used memory.
2. We’ll create a void display function using the method of traversal. Pass this array to the display function by value or by reference. And print the elements. Printing the elements of an array has already been covered in my C playlist. Visit now if you haven’t yet.
3. We’ll now create an integer function insertion (integer, just to check if the operation succeeds). Before that, create an integer variable size to store the used size of the array. Pass into this void function the array and its used size, the element to be inserted and the total size, and the index where it is inserted.
4. In the insertion function, write the case of validity. Here, we’ll check if the index is within the range [0,100]. We’ll continue if it's valid; otherwise, return -1.
5. Create a for loop to shift the elements from the index to the last element to their adjacent right. This way, we’ll create a void at the index we want to insert in.
6. Insert the element in the index. Return 1 on completion.
*/