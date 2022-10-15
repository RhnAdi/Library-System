#ifndef UPDATE_BOOK_LIBRARY_H
#define UPDATE_BOOK_LIBRARY_H
#include "update.c"

struct Book UpdateBook(struct Library *lib, struct Book book, char *error);

#endif