// Implementing an Array as an Abstract Data Type

#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void printArray(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void setValue(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter Element %d: ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 5);

    printf("We are running setValue now:\n");
    setValue(&marks);
    printf("We are running printArray now:\n");
    printArray(&marks);
    return 0;
}

/* Understanding Code:
1. First, we will define a structure.Define the structure elements, integer variables total_size and used_size, and an integer pointer to point at the address of the first element.
2. We are now ready with our customized data type. Let’s define some functions, which will feature -
    Creating an array of this data type,
    Printing the contents of this array,
    Setting values in this array.
3. Create a void function createArray by passing the address of a struct data type a, and integers tSize and uSize. We can very easily assign this tSize and uSize given from the main, to the total_size and used_size of the struct myArray a.
4. Similarly, assign the integer pointer ptr, the address of the reserved memory location using malloc. Do use the header file <stdlib.h> for using malloc.
5. We will now create a printArray function to display all the elements of the struct myArray. We will simply pass the address of the struct myArray a. To print all the elements, we will traverse through the whole struct and print each struct element till the iterator reaches the last element. We will use a→used_size to define the loop size. Use (a→ptr)[i] to access each element.
6. We will now create a setValue function to set values to this struct myArray a and pass the address of the same. Use scanf to assign values to each element via (a→ptr)[i] .
*/