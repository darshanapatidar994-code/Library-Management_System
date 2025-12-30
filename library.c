#include <stdio.h>
#include <stdlib.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

void addBook(FILE *fp) {
    struct Book b;
    printf("Enter ID: ");
    scanf("%d", &b.id);
    printf("Enter Title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter Author: ");
    scanf(" %[^\n]", b.author);
    fwrite(&b, sizeof(b), 1, fp);
    printf("\nBook Added:\n");
    printf("%d | %s | %s\n", b.id, b.title, b.author);
}

void viewBooks(FILE *fp) {
    struct Book b;
    rewind(fp);
    printf("\nAll Books:\n");
    while (fread(&b, sizeof(b), 1, fp) == 1) {
        printf("%d | %s | %s\n", b.id, b.title, b.author);
    }
}

int main() {
    FILE *fp = fopen("books.dat", "ab+");
    if (!fp) {
        printf("Error opening file\n");
        return 1;
    }
    int choice;
    while (1) {
        printf("\n1. Add Book\n2. View Books\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) addBook(fp);
        else if (choice == 2) viewBooks(fp);
        else if (choice == 3) break;
        else printf("Invalid choice\n");
    }
    fclose(fp);
    return 0;
}
