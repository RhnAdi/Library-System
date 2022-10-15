#ifndef ADD_BOOK_LIBRARY_H
#define ADD_BOOK_LIBRARY_H
#include "add.c"

struct Book AddBook(struct Library *library, struct Book book, char *error);

#endif