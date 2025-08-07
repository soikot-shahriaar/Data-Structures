#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room
{
    int roomNumber;
    char roomType[20];  // ICU, General, Emergency, etc.
    int isOccupied;
    char patientName[50];
    char doctorName[50];
    int patientAge;
    struct Room *next;
};

struct Room *head = NULL;

// Display the status of all rooms
void displayRoomStatus()
{
    printf("\nHOSPITAL ROOM STATUS:\n");
    printf("=====================\n");
    struct Room *current = head;

    if (current == NULL)
    {
        printf("No rooms in the hospital.\n");
        return;
    }

    while (current != NULL)
    {
        printf("ROOM %d (%s): ", current->roomNumber, current->roomType);

        if (current->isOccupied)
        {
            printf("OCCUPIED BY %s (AGE: %d) | DOCTOR: %s\n", 
                   current->patientName, current->patientAge, current->doctorName);
        }
        else
        {
            printf("VACANT\n");
        }

        current = current->next;
    }
}

// Add a new room to the hospital
void addRoom(int roomNumber, char roomType[])
{
    struct Room *newRoom = (struct Room *)malloc(sizeof(struct Room));

    newRoom->roomNumber = roomNumber;
    strcpy(newRoom->roomType, roomType);
    newRoom->isOccupied = 0;
    strcpy(newRoom->patientName, "");
    strcpy(newRoom->doctorName, "");
    newRoom->patientAge = 0;

    newRoom->next = head;
    head = newRoom;

    printf("ROOM %d (%s) ADDED TO HOSPITAL\n", roomNumber, roomType);
}

// Admit a patient to a room
void admitPatient(int roomNumber, char patientName[], int patientAge, char doctorName[])
{
    struct Room *current = head;

    while (current != NULL && current->roomNumber != roomNumber)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        if (!current->isOccupied)
        {
            current->isOccupied = 1;
            strcpy(current->patientName, patientName);
            strcpy(current->doctorName, doctorName);
            current->patientAge = patientAge;
            printf("PATIENT %s (AGE: %d) ADMITTED TO ROOM %d | DOCTOR: %s\n", 
                   patientName, patientAge, roomNumber, doctorName);
        }
        else
        {
            printf("ROOM %d IS ALREADY OCCUPIED BY %s\n", roomNumber, current->patientName);
        }
    }
    else
    {
        printf("ROOM %d NOT FOUND IN HOSPITAL.\n", roomNumber);
    }
}

// Discharge a patient from a room
void dischargePatient(int roomNumber)
{
    struct Room *current = head;

    while (current != NULL && current->roomNumber != roomNumber)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        if (current->isOccupied)
        {
            printf("PATIENT %s DISCHARGED FROM ROOM %d\n", current->patientName, roomNumber);
            current->isOccupied = 0;
            strcpy(current->patientName, "");
            strcpy(current->doctorName, "");
            current->patientAge = 0;
        }
        else
        {
            printf("ROOM %d IS ALREADY VACANT.\n", roomNumber);
        }
    }
    else
    {
        printf("ROOM %d NOT FOUND IN HOSPITAL.\n", roomNumber);
    }
}

// Transfer a patient to another room
void transferPatient(int fromRoom, int toRoom)
{
    struct Room *fromRoomPtr = head;
    struct Room *toRoomPtr = head;
    char tempPatientName[50], tempDoctorName[50];
    int tempPatientAge;

    // Find both rooms
    while (fromRoomPtr != NULL && fromRoomPtr->roomNumber != fromRoom)
        fromRoomPtr = fromRoomPtr->next;
    
    while (toRoomPtr != NULL && toRoomPtr->roomNumber != toRoom)
        toRoomPtr = toRoomPtr->next;

    if (fromRoomPtr == NULL)
    {
        printf("ROOM %d NOT FOUND IN HOSPITAL.\n", fromRoom);
        return;
    }
    
    if (toRoomPtr == NULL)
    {
        printf("ROOM %d NOT FOUND IN HOSPITAL.\n", toRoom);
        return;
    }

    if (!fromRoomPtr->isOccupied)
    {
        printf("ROOM %d IS VACANT. NO PATIENT TO TRANSFER.\n", fromRoom);
        return;
    }

    if (toRoomPtr->isOccupied)
    {
        printf("ROOM %d IS OCCUPIED BY %s. CANNOT TRANSFER.\n", toRoom, toRoomPtr->patientName);
        return;
    }

    // Transfer patient data
    strcpy(tempPatientName, fromRoomPtr->patientName);
    strcpy(tempDoctorName, fromRoomPtr->doctorName);
    tempPatientAge = fromRoomPtr->patientAge;

    // Clear from room
    fromRoomPtr->isOccupied = 0;
    strcpy(fromRoomPtr->patientName, "");
    strcpy(fromRoomPtr->doctorName, "");
    fromRoomPtr->patientAge = 0;

    // Assign to new room
    toRoomPtr->isOccupied = 1;
    strcpy(toRoomPtr->patientName, tempPatientName);
    strcpy(toRoomPtr->doctorName, tempDoctorName);
    toRoomPtr->patientAge = tempPatientAge;

    printf("PATIENT %s TRANSFERRED FROM ROOM %d TO ROOM %d\n", tempPatientName, fromRoom, toRoom);
}

// Remove a room from the hospital
void removeRoom(int roomNumber)
{
    struct Room *current = head;
    struct Room *prev = NULL;

    while (current != NULL && current->roomNumber != roomNumber)
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL)
    {
        if (current->isOccupied)
        {
            printf("CANNOT REMOVE ROOM %d - PATIENT %s IS STILL ADMITTED.\n", 
                   roomNumber, current->patientName);
            return;
        }

        if (prev != NULL)
            prev->next = current->next;
        else
            head = current->next;

        printf("ROOM %d REMOVED FROM HOSPITAL\n", roomNumber);
        free(current);
    }
    else
    {
        printf("ROOM %d NOT FOUND IN HOSPITAL.\n", roomNumber);
    }
}

// Display user guide
void displayGuide()
{
    printf("\n");
    printf("** * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*        HOSPITAL ROOM MANAGEMENT SYSTEM         *\n");
    printf("*  (this program manages hospital rooms, patient *\n");
    printf("*     admissions, discharges, and transfers)     *\n");
    printf("** * * * * * * * * * * * * * * * * * * * * * * * *\n");

    printf("** * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*                MENU OPTIONS:                   *\n");
    printf("*                                                *\n");
    printf("* 1. USER GUIDE: Display this User Guide.        *\n");
    printf("* 2. ADD ROOM: Add a new room to hospital.       *\n");
    printf("* 3. ADMIT PATIENT: Admit patient to a room.     *\n");
    printf("* 4. DISCHARGE PATIENT: Discharge from room.     *\n");
    printf("* 5. TRANSFER PATIENT: Transfer to another room. *\n");
    printf("* 6. REMOVE ROOM: Remove room from hospital.     *\n");
    printf("* 7. DISPLAY ROOM STATUS: View all rooms.        *\n");
    printf("* 8. EXIT: Quit the program.                     *\n");
    printf("*                                                *\n");
    printf("** * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n");
}

int main()
{
    // Variable Declaration
    int choice, roomNumber, patientAge, fromRoom, toRoom;
    char roomType[20], patientName[50], doctorName[50];

    // Menu-driven Loop
    while (1)
    {
        printf("\nHOSPITAL ROOM MANAGEMENT SYSTEM MENU:\n");
        printf("1. OPEN USER GUIDE\n");
        printf("2. ADD ROOM\n");
        printf("3. ADMIT PATIENT\n");
        printf("4. DISCHARGE PATIENT\n");
        printf("5. TRANSFER PATIENT\n");
        printf("6. REMOVE ROOM\n");
        printf("7. DISPLAY ROOM STATUS\n");
        printf("8. EXIT\n");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        getchar(); // Clear buffer

        switch (choice)
        {
        case 1:
            displayGuide();
            break;
        case 2:
            printf("ENTER ROOM NUMBER: ");
            scanf("%d", &roomNumber);
            getchar();
            printf("ENTER ROOM TYPE (ICU/General/Emergency): ");
            fgets(roomType, sizeof(roomType), stdin);
            roomType[strcspn(roomType, "\n")] = 0;
            addRoom(roomNumber, roomType);
            break;
        case 3:
            printf("ENTER ROOM NUMBER FOR ADMISSION: ");
            scanf("%d", &roomNumber);
            getchar();
            printf("ENTER PATIENT NAME: ");
            fgets(patientName, sizeof(patientName), stdin);
            patientName[strcspn(patientName, "\n")] = 0;
            printf("ENTER PATIENT AGE: ");
            scanf("%d", &patientAge);
            getchar();
            printf("ENTER DOCTOR NAME: ");
            fgets(doctorName, sizeof(doctorName), stdin);
            doctorName[strcspn(doctorName, "\n")] = 0;
            admitPatient(roomNumber, patientName, patientAge, doctorName);
            break;
        case 4:
            printf("ENTER ROOM NUMBER FOR DISCHARGE: ");
            scanf("%d", &roomNumber);
            dischargePatient(roomNumber);
            break;
        case 5:
            printf("ENTER ROOM NUMBER TO TRANSFER FROM: ");
            scanf("%d", &fromRoom);
            printf("ENTER ROOM NUMBER TO TRANSFER TO: ");
            scanf("%d", &toRoom);
            transferPatient(fromRoom, toRoom);
            break;
        case 6:
            printf("ENTER ROOM NUMBER TO REMOVE: ");
            scanf("%d", &roomNumber);
            removeRoom(roomNumber);
            break;
        case 7:
            displayRoomStatus();
            break;
        case 8:
            printf("EXITING THE PROGRAM.\nTHANKS FOR USING OUR HOSPITAL SYSTEM!\n");
            return 0;
        default:
            printf("INVALID CHOICE. TRY AGAIN PLEASE!\n");
        }
    }

    return 0;
}
