#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

typedef struct {
    int bookID;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
} Book;


void displayMenu();
void addBook(Book books[], int *count);
void toLower(char *str);
void searchBook(Book books[], int count, char title[]);
void displayBooks(Book books[], int count);

void toLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main() {
    Book library[MAX_BOOKS]; 
    int bookCount = 0;       
    int choice;              
    char searchTitle[MAX_TITLE_LENGTH]; 

    do {
        displayMenu();
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number between 1 and 4.\n");
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                printf("\n--- Add New Book ---\n");
                addBook(library, &bookCount);
                break;
            case 2:
                printf("\n--- Search Book by Title ---\n");
                printf("Enter Title to Search: ");
                if (fgets(searchTitle, MAX_TITLE_LENGTH, stdin) != NULL) {
                    searchTitle[strcspn(searchTitle, "\n")] = 0; 
                    searchBook(library, bookCount, searchTitle);
                }
                break;
            case 3:
                printf("\n--- All Books in Library ---\n");
                displayBooks(library, bookCount);
                break;
            case 4:
                printf("\nExiting program. Goodbye! 👋\n");
                break;
            default:
                printf("\nInvalid option. Please choose an option between 1 and 4.\n");
        }
        printf("\n----------------------------------------------\n");

    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n\n===== Library Management System (C) =====\n");
    printf("1. Add New Book\n");
    printf("2. Search Book by Title\n");
    printf("3. Display All Books\n");
    printf("4. Exit Program\n");
    printf("=========================================\n");
}

void addBook(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter Book ID: ");
    while (scanf("%d", &books[*count].bookID) != 1) {
        printf("Invalid input. Please enter an integer for Book ID: ");
        while (getchar() != '\n'); 
    }
    while (getchar() != '\n'); 

    printf("Enter Title: ");
    if (fgets(books[*count].title, MAX_TITLE_LENGTH, stdin) != NULL) {
        books[*count].title[strcspn(books[*count].title, "\n")] = 0;
    } else {
        printf("Error reading title.\n");
        return;
    }
    
    printf("Enter Author: ");
    if (fgets(books[*count].author, MAX_AUTHOR_LENGTH, stdin) != NULL) {
        books[*count].author[strcspn(books[*count].author, "\n")] = 0;
    } else {
        printf("Error reading author.\n");
        return;
    }

    printf("Enter Year: ");
    while (scanf("%d", &books[*count].year) != 1) {
        printf("Invalid input. Please enter an integer for Year: ");
        while (getchar() != '\n'); 
    }
    while (getchar() != '\n');

    (*count)++; 
    printf("\nBook added successfully! \n");
}

void searchBook(Book books[], int count, char title[]) {
    int found = 0;
    
    char searchTitleLower[MAX_TITLE_LENGTH];
    char bookTitleLower[MAX_TITLE_LENGTH];
    
    strncpy(searchTitleLower, title, MAX_TITLE_LENGTH);
    searchTitleLower[MAX_TITLE_LENGTH - 1] = '\0';
    toLower(searchTitleLower); 

    for (int i = 0; i < count; i++) {
        strncpy(bookTitleLower, books[i].title, MAX_TITLE_LENGTH);
        bookTitleLower[MAX_TITLE_LENGTH - 1] = '\0';
        toLower(bookTitleLower);
        
        if (strstr(bookTitleLower, searchTitleLower) != NULL) {
            printf("\nBook found! 🔍\n");
            printf("Book ID: %d\n", books[i].bookID);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Year: %d\n", books[i].year);
            found = 1;
        }
    }

    if (!found) {
        printf("\nBook not found. \n");
    }
}

void displayBooks(Book books[], int count) {
    if (count == 0) {
        printf("The library is empty. No books to display.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n--- Book %d ---\n", i + 1);
        printf("Book ID: %d\n", books[i].bookID);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Year: %d\n", books[i].year);
    }
}