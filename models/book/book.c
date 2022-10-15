#include <stdio.h>
#include <string.h>

struct Book {
    char ID[10];
    char Title[32];
    char Description[200];
    char Publisher[20];
    char Author[20];
    int Year;
    int CountPage;
    int Quantity;
    int Borrowed;
};

struct Book initBook(
    char id[],
    char title[],
    char description[],
    char publisher[],
    char author[],
    int year,
    int count_page,
    int quantity,
    int borrowed
) {
    struct Book book;
    strcpy(book.ID, id);
    strcpy(book.Title, title);
    strcpy(book.Description, description);
    strcpy(book.Author, author);
    strcpy(book.Publisher, publisher);
    book.Year = year;
    book.CountPage = count_page;
    book.Quantity = quantity;
    book.Borrowed = borrowed;
    return book;
}