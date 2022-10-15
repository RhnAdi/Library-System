#include <stdio.h>
#include <stdlib.h>
#include "../../../models/borrowing_list/borrowing_list.h"

void ListBorrowingHandler(struct BorrowingList *borrowing_list) {
    system("clear");
    printf("+-------------------------------------------+\n");
    printf("| \t\tList Borrowing\t\t    |\n");
    printf("+-------------------------------------------+\n");

    for (int i = 0; i < borrowing_list->count; i++) {
        printf("| Nomor : %i \n", i + 1);
        printf("| ID book : %s \n", borrowing_list->list[i].book->ID);
        printf("| Title book : %s \n", borrowing_list->list[i].book->Title);
        printf("| NIM : %i \n", borrowing_list->list[i].mahasiswa.NIM);
        printf("| Name : %s \n", borrowing_list->list[i].mahasiswa.Name);
        printf("+-------------------------------------------+\n");
    }

    return;
}