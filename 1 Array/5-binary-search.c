#include <stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    // Keep searching until low <= high
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    // Sorted array for binary search
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr) / sizeof(int);
    int element = 123;
    
    int searchIndex = binarySearch(arr, size, element);

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

/* Understanding Code: (Binary Search)
1. Create a function named binarySearch and pass the same three parameters the array, its size, and the element to be searched. Here, we will maintain three integer variables low, mid, and high. Low  stores are the beginning of the search space, and high stores the end. Mid stores the middle element of our search space, which is  mid = (low+high)/2.
2. Check whether the mid element equals the search element. If yes, return mid, else if the mid element is greater than the search element, then the search element must lie on the left side of the current space and high becomes mid-1, else if the mid element is less than the search element, then we’ll shift to the right side, and low becomes mid+1.
3. This way, we reduce our search space into half every time we repeat step 2. Now our new mid becomes (low+high)/2, and we repeat step 2. And keep repeating until either we find the search element or the low becomes greater than the high.
*/