#ifndef DELETE_BORROWING_H
#define DELETE_BORROWING_H
#include <stdbool.h>
#include "delete.c"

bool DeleteBorrowing(struct BorrowingList *borrowing_list, int id, char *error);

#endif