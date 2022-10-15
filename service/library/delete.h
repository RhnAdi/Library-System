#ifndef DELETE_BOOK_LIBRARY_H
#define DELETE_BOOK_LIBRARY_H
#include <stdbool.h>
#include "delete.c"

bool DeleteBook(struct Library *lib, char *id, char *error);

#endif