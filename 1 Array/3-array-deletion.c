#include <stdio.h>

void display(int arr[], int n)
{
    // Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deletion(int arr[], int size, int index)
{
    // Deletion
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[100] = {11, 22, 33, 44, 55};
    int size = 5, index = 1;
    printf("Before Deletion: ");
    display(arr, size);

    deletion(arr, size, index);
    size--;
    printf("Before Deletion: ");
    display(arr, size);
    return 0;
}

/* Understanding Code:
1. One thing which will remain as it is, is the display function.
2. We have to make minimal changes in the insertion function to make it a deletion function.
3. Rename it deletion. The index and the array, and its size will be our only parameters this time.
4. Replace the right shift with the left shift. Just assign array[i], the value present in array[i+1].
5. We are done deleting the element at some specified index and we can now check if the program actually works for deleting the element at some index.
6. We’ll create an array with 5 elements and display it before and after deleting an element at index 1.
*/