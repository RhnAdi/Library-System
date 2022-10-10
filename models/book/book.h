#ifndef BOOK_H
#define BOOK_H
#include "book.c"

struct Book;

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
);

#endif