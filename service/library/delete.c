#include "../../models/library/library.h"
#include <stdbool.h>
#include <stdio.h>
#include "../../error/error.h"

bool DeleteBook(struct Library *lib, char *id, char *error) {
    for (int i = 0; i < lib->count; i++) {
        int compare = strcmp(id, lib->books[i].ID);
        if (compare == 0) {
            for (int j = i + 1; j < lib->count; j++) {
                lib->books[i] = lib->books[j];
            }
            lib->count = lib->count - 1;
            return true;
        }
    }

    strcpy(error, BOOK_NOT_FOUND);
    return false;
}