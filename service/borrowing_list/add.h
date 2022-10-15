#ifndef ADD_BORROWING_H
#define ADD_BORROWING_H

#include "add.c"

struct Borrowing AddBorrowing(
    struct Library *library, 
    struct BorrowingList *borrowing_list, 
    struct Mahasiswa mahasiswa,
    char *id, 
    char *error
);

#endif