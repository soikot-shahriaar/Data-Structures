#include <stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    // Unsorted array for linear search
    int arr[] = {1, 3, 5, 57, 4, 6, 23, 5, 4, 54, 56, 34};
    int size = sizeof(arr) / sizeof(int); // number of elements of array
    int element = 45;
    
    int searchIndex = linearSearch(arr, size, element);

    if (searchIndex != -1)
    {
        printf("The element %d was found at index %d \n", element, searchIndex);
    }
    else
    {
        printf("The element %d was not found in the array \n", element);
    }

    return 0;
}

/* Understanding the Code: (Linear Search)
1. Create an integer function linearSearch. This function will receive the array, its size, and the element to be searched as its parameters.
2. Run a for loop from its 0 to the last index, checking the if condition at every index whether the element at that index equals the search element. If yes, return the index, else continue the search.
3. If the element could not be found until the last, return -1.
*/