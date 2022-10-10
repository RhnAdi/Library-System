#include "../../models/library/library.h"
#include "../../error/error.h"
#include <string.h>

struct Book GetBook(struct Library *library, char *id, char *error){
    for (int i = 0; i <= library->count; i++ ) {
        int result = strcmp(id, library->books[i].ID);
        if (result == 0) {
            return library->books[i];
        }
    };

    strcpy(error, BOOK_NOT_FOUND);
};