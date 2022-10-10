#include "../../models/book/book.h"
#include "../../models/library/library.h"

struct Book UpdateBook(struct Library *lib, struct Book book, char *error) {
    for (int i = 0; i <= lib->count; i++) {
        if (strcmp(lib->books[i].ID, book.ID) == 0) {
            strcpy(lib->books[i].Title, book.Title);
            strcpy(lib->books[i].Description, book.Description);
            strcpy(lib->books[i].Author, book.Author);
            strcpy(lib->books[i].Publisher, book.Publisher);
            lib->books[i].CountPage = book.CountPage;
            lib->books[i].Year = book.Year;
            return lib->books[i];
        }
    }
}