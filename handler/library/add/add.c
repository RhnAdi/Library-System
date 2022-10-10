#include <stdio.h>
#include "../../../models/library/library.h"
#include "../../../models/book/book.h"
#include "../../../service/library/library.h"
#include <string.h>

void AddBookHandler(struct Library *lib) {
    char id[10], title[20], description[200], publisher[20], author[20];
    int year, page_count, quantity;

    system("clear");
    printf("\t \033[0;32m Add Book To Library \033[0;30m \n");
    printf("-------------------------------------------------- \n");

    printf("input id : "); scanf("%s", id);
    printf("input title : "); scanf("%s", title);
    printf("input description : "); scanf("%s", description);
    printf("input publisher : "); scanf("%s", publisher);
    printf("input author : "); scanf("%s", author);
    printf("input year : "); scanf("%i", &year);
    printf("input count page : "); scanf("%i", &page_count);
    printf("input quantity : "); scanf("%i", &quantity);

    struct Book new_book;
    strcpy(new_book.ID, id);
    strcpy(new_book.Title, title);
    strcpy(new_book.Author, author);
    strcpy(new_book.Description, description);
    strcpy(new_book.Publisher, publisher);

    new_book.Year = year;
    new_book.CountPage = page_count;
    new_book.Quantity = quantity;

    char error[20];
    struct Book result = AddBook(lib, new_book, error);
    if (strlen(error) > 0){
        printf("error -> %s \n", error);
    } 
}