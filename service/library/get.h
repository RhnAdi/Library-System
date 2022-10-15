#ifndef GET_BOOK_LIBRARY_H
#define GET_BOOK_LIBRARY_H
#include "get.c"

struct Book *GetBook(struct Library *library, char *id, char *error);

#endif