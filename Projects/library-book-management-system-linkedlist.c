#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int bookId;
    char title[100];
    char author[50];
    int isAvailable;
    char borrowerName[50];
    struct Book *next;
};

struct Book *head = NULL;

// Display the status of all books
void displayBookStatus()
{
    printf("\nLIBRARY BOOK STATUS:\n");
    printf("===================\n");
    struct Book *current = head;

    if (current == NULL)
    {
        printf("No books in the library.\n");
        return;
    }

    while (current != NULL)
    {
        printf("BOOK ID: %d | TITLE: %s | AUTHOR: %s | STATUS: ", 
               current->bookId, current->title, current->author);

        if (current->isAvailable)
            printf("AVAILABLE\n");
        else
            printf("BORROWED BY: %s\n", current->borrowerName);

        current = current->next;
    }
}

// Add a new book to the library
void addBook(int bookId, char title[], char author[])
{
    struct Book *newBook = (struct Book *)malloc(sizeof(struct Book));

    newBook->bookId = bookId;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->isAvailable = 1;
    strcpy(newBook->borrowerName, "");

    newBook->next = head;
    head = newBook;

    printf("BOOK '%s' BY %s ADDED TO LIBRARY WITH ID %d\n", title, author, bookId);
}

// Borrow a book by book ID
void borrowBook(int bookId, char borrowerName[])
{
    struct Book *current = head;

    while (current != NULL && current->bookId != bookId)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        if (current->isAvailable)
        {
            current->isAvailable = 0;
            strcpy(current->borrowerName, borrowerName);
            printf("BOOK '%s' SUCCESSFULLY BORROWED BY %s\n", current->title, borrowerName);
        }
        else
        {
            printf("BOOK '%s' IS ALREADY BORROWED BY %s\n", current->title, current->borrowerName);
        }
    }
    else
    {
        printf("BOOK WITH ID %d NOT FOUND IN LIBRARY.\n", bookId);
    }
}

// Return a book by book ID
void returnBook(int bookId)
{
    struct Book *current = head;

    while (current != NULL && current->bookId != bookId)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        if (!current->isAvailable)
        {
            printf("BOOK '%s' SUCCESSFULLY RETURNED BY %s\n", current->title, current->borrowerName);
            current->isAvailable = 1;
            strcpy(current->borrowerName, "");
        }
        else
        {
            printf("BOOK '%s' IS ALREADY AVAILABLE IN LIBRARY.\n", current->title);
        }
    }
    else
    {
        printf("BOOK WITH ID %d NOT FOUND IN LIBRARY.\n", bookId);
    }
}

// Remove a book from the library
void removeBook(int bookId)
{
    struct Book *current = head;
    struct Book *prev = NULL;

    while (current != NULL && current->bookId != bookId)
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL)
    {
        if (prev != NULL)
            prev->next = current->next;
        else
            head = current->next;

        printf("BOOK '%s' REMOVED FROM LIBRARY\n", current->title);
        free(current);
    }
    else
    {
        printf("BOOK WITH ID %d NOT FOUND IN LIBRARY.\n", bookId);
    }
}

// Display user guide
void displayGuide()
{
    printf("\n");
    printf("** * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*         LIBRARY BOOK MANAGEMENT SYSTEM         *\n");
    printf("*  (this program manages books, borrowing, and   *\n");
    printf("*     returning operations in the library)       *\n");
    printf("** * * * * * * * * * * * * * * * * * * * * * * * *\n");

    printf("** * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*                MENU OPTIONS:                   *\n");
    printf("*                                                *\n");
    printf("* 1. USER GUIDE: Display this User Guide.        *\n");
    printf("* 2. ADD BOOK: Add a new book to library.        *\n");
    printf("* 3. BORROW BOOK: Borrow a book by ID.           *\n");
    printf("* 4. RETURN BOOK: Return a borrowed book.        *\n");
    printf("* 5. REMOVE BOOK: Remove a book from library.    *\n");
    printf("* 6. DISPLAY BOOK STATUS: View all books.        *\n");
    printf("* 7. EXIT: Quit the program.                     *\n");
    printf("*                                                *\n");
    printf("** * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\n");
}

int main()
{
    // Variable Declaration
    int choice, bookId;
    char title[100], author[50], borrowerName[50];

    // Menu-driven Loop
    while (1)
    {
        printf("\nLIBRARY BOOK MANAGEMENT SYSTEM MENU:\n");
        printf("1. OPEN USER GUIDE\n");
        printf("2. ADD BOOK\n");
        printf("3. BORROW BOOK\n");
        printf("4. RETURN BOOK\n");
        printf("5. REMOVE BOOK\n");
        printf("6. DISPLAY BOOK STATUS\n");
        printf("7. EXIT\n");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        getchar(); // Clear buffer

        switch (choice)
        {
        case 1:
            displayGuide();
            break;
        case 2:
            printf("ENTER BOOK ID: ");
            scanf("%d", &bookId);
            getchar();
            printf("ENTER BOOK TITLE: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0;
            printf("ENTER AUTHOR NAME: ");
            fgets(author, sizeof(author), stdin);
            author[strcspn(author, "\n")] = 0;
            addBook(bookId, title, author);
            break;
        case 3:
            printf("ENTER BOOK ID TO BORROW: ");
            scanf("%d", &bookId);
            getchar();
            printf("ENTER BORROWER NAME: ");
            fgets(borrowerName, sizeof(borrowerName), stdin);
            borrowerName[strcspn(borrowerName, "\n")] = 0;
            borrowBook(bookId, borrowerName);
            break;
        case 4:
            printf("ENTER BOOK ID TO RETURN: ");
            scanf("%d", &bookId);
            returnBook(bookId);
            break;
        case 5:
            printf("ENTER BOOK ID TO REMOVE: ");
            scanf("%d", &bookId);
            removeBook(bookId);
            break;
        case 6:
            displayBookStatus();
            break;
        case 7:
            printf("EXITING THE PROGRAM.\nTHANKS FOR USING OUR LIBRARY SYSTEM!\n");
            return 0;
        default:
            printf("INVALID CHOICE. TRY AGAIN PLEASE!\n");
        }
    }

    return 0;
}
