#ifndef SERVICE_LIBRARY_H
#define SERVICE_LIBRARY_H

#include "add.c"
#include "get.c"
#include "update.c"
#include "delete.c"
#include <stdbool.h>

struct Book AddBook(struct Library *library, struct Book book, char *error);
struct Book GetBook(struct Library *library, char *id, char *error);
struct Book UpdateBook(struct Library *library, struct Book book, char *error);
bool DeleteBook(struct Library *lib, char *id, char *error);

#endif