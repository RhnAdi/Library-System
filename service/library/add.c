#include "../../models/book/book.h"
#include "../../models/library/library.h"
#include "../../error/error.h"
#include <string.h>

struct Book AddBook(struct Library *library, struct Book book, char *error){
    book.Borrowed = 0;
    for (int i = 0; i < library->count; i++) {
        int compare = strcmp(book.ID, library->books[i].ID);
        if (compare == 0) {
            strcpy(error, BOOK_ALREADY_EXIST);
            return book;
        }
    }

    if (library->count == 0) {
        library->books[0] = book;
    } else {
        library->books[library->count] = book;
    }
    library->count += 1;

    return book;
}