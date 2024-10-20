#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 50
#define AUTHOR_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int id;
} Book;

Book library[MAX_BOOKS];
int book_count = 0;

void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    
    printf("Enter book title: ");
    scanf(" %[^\n]", library[book_count].title);
    printf("Enter author name: ");
    scanf(" %[^\n]", library[book_count].author);
    library[book_count].id = book_count + 1;  // Simple ID assignment
    book_count++;
    printf("Book added successfully!\n");
}

void viewBooks() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }
    
    printf("Books in the library:\n");
    for (int i = 0; i < book_count; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
    }
}

void searchBook() {
    char title[TITLE_LENGTH];
    printf("Enter book title to search: ");
    scanf(" %[^\n]", title);
    
    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(library[i].title, title) == 0) {
            printf("Book found! ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
