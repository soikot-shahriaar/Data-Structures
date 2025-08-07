#include <stdio.h>
#include <stdlib.h>

struct Platform
{
    int platformNumber;
    int isOccupied;
    int trainNumber;
    struct Platform *next;
};

struct Platform *head = NULL;

// Display the occupancy status of all platforms
void displayPlatformStatus()
{
    printf("\nPLATFORM STATUS:\n");
    struct Platform *current = head;

    while (current != NULL)
    {
        printf("PLATFORM %d: ", current->platformNumber);

        if (current->isOccupied)
            printf("OCCUPIED\n");
        else
            printf("FREE\n");

        current = current->next;
    }
}

// Allocate a platform by platform number
// This function is responsible for allocating a new platform by creating a new node and updating the linked list.
void allocatePlatform(int platformNumber, int trainNumber)
{
    struct Platform *newPlatform = (struct Platform *)malloc(sizeof(struct Platform));

    newPlatform->platformNumber = platformNumber;
    newPlatform->isOccupied = 1;
    newPlatform->trainNumber = trainNumber;

    newPlatform->next = head;
    head = newPlatform;

    printf("PLATFORM %d ALLOCATED FOR TRAIN %d\n", platformNumber, trainNumber);
}

// Deallocate a platform by platform number
// This function searches for a platform with a specified platform number, removes it from the linked list, and frees the associated memory if the platform is found.
void deallocatePlatform(int platformNumber)
{
    struct Platform *current = head;
    struct Platform *prev = NULL;

    while (current != NULL && current->platformNumber != platformNumber)
    {
        prev = current;
        current = current->next;
    }

    // This if statement checks whether the platform with the specified platformNumber has been found.
    if (current != NULL)
    {
        if (prev != NULL)
            prev->next = current->next;
        else
            head = current->next;

        printf("PLATFORM %d DEALLOCATED FOR TRAIN %d\n", platformNumber, current->trainNumber);
        free(current);
    }
    else
        printf("PLATFORM %d IS NOT CURRENTLY OCCUPIED.\n", platformNumber);
}

// Display user guides message
void displayGuide()
{
    printf("\n");
    printf("** * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*    AUTOMATED TRAIN STATION MANAGEMENT SYSTEM   *\n");
    printf("*  (this program automates platform allocations  *\n");
    printf("*     and deallocations in the train station)    *\n");
    printf("** * * * * * * * * * * * * * * * * * * * * * * * *\n");

    printf("** * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*                MENU OPTIONS:                   *\n");
    printf("*                                                *\n");
    printf("* 1. USER GUIDE: Display this User Guides.       *\n");
    printf("* 2. ALLOCATE PLATFORM: Allocate a platform by   *\n");
    printf("*    specifying its number and the train number. *\n");
    printf("* 3. DEALLOCATE PLATFORM: Deallocate a platform  *\n");
    printf("*    by specifying its number.                   *\n");
    printf("* 4. DISPLAY PLATFORM STATUS: View the occupancy *\n");
    printf("*    status of all platforms.                    *\n");
    printf("* 5. EXIT: Quit the program.                     *\n");
    printf("*                                                *\n");
    printf("** * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n");
}

int main()
{
    // Variable Declaration
    int choice, trainNumber, platformNumber;

    // Menu-driven Loop
    while (1)
    {
        printf("\nTRAIN STATION MANAGEMENT SYSTEM MENU:\n");
        printf("1. OPEN USER GUIDE\n");
        printf("2. ALLOCATE PLATFORM\n");
        printf("3. DEALLOCATE PLATFORM\n");
        printf("4. DISPLAY PLATFORM STATUS\n");
        printf("5. EXIT\n");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayGuide();
            break;
        case 2:
            printf("ENTER THE PLATFORM NUMBER TO ALLOCATE: ");
            scanf("%d", &platformNumber);
            printf("ENTER THE TRAIN NUMBER FOR PLATFORM %d: ", platformNumber);
            scanf("%d", &trainNumber);
            allocatePlatform(platformNumber, trainNumber);
            break;
        case 3:
            printf("ENTER THE PLATFORM NUMBER TO DEALLOCATE: ");
            scanf("%d", &platformNumber);
            deallocatePlatform(platformNumber);
            break;
        case 4:
            displayPlatformStatus();
            break;
        case 5:
            printf("EXITING THE PROGRAM.\nTHANKS FOR USING OUR SYSTEM !\n");
            return 0;
        default:
            printf("INVALID CHOICE. TRY AGAIN PLEASE !\n");
        }
    }

    return 0;
}