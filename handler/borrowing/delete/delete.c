#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../../models/borrowing_list/borrowing_list.h"
#include "../../../service/borrowing_list/delete.h"

void DeleteBorrowingHandler(struct BorrowingList *borrowing_list) {
    printf("+----------------------------------------------+\n");
    printf("|\t\tDelete Borrowing\t\t|\n");
    printf("+----------------------------------------------+\n");

    int borrowing_nomor;

    printf("input borrowing number : "); scanf("%i", &borrowing_nomor);

    char error[20] = {};
    bool deleted = DeleteBorrowing(borrowing_list, borrowing_nomor, error);
    if(strlen(error) > 0) {
        printf("warning : %s \n", error);
        return;
    }

    printf("deleted borrowing \n");
    return;
}