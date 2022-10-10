#include "../../models/borrowing_list/borrowing_list.h"
#include "../../error/error.h"
#include <stdbool.h>
#include <string.h>

bool DeleteBorrowing(struct BorrowingList *borrowing_list, int id, char *error) {
    if (id - 1 <= borrowing_list->count) {
        for (int i = id; i < borrowing_list->count; i++) {
            borrowing_list->list[i - 1] = borrowing_list->list[i];
        }
        borrowing_list->count--;
        return true;
    }
    strcpy(error, BORROWING_NOT_FOUND);
    return false;
}