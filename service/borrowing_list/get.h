#ifndef GET_BORROWING_H
#define GET_BORROWING_H
#include "get.c"

struct Borrowing GetBorrowing(struct BorrowingList *borrowing_list, int id, char *error);

#endif