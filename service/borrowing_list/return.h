#ifndef RETURN_BORROWING_H
#define RETURN_BORROWING_H
#include "return.c"

struct Borrowing ReturnBorrowing(struct BorrowingList *borrowing_list, int id, char *error);

#endif