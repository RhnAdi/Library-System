#include "../../models/library/library.h"
#include "../../models/borrowing_list/borrowing_list.h"
#include "./get/get.h"
#include "./add/add.h"
#include "./list/list.h"
#include "./return/return.h"
#include "./delete/delete.h"
#include <stdio.h>
void BorrowingHandler(struct Library *library, struct BorrowingList *borrowing_list) {
    printf("+-------------------------------------------------------+\n");
    printf("|\t\t\tLibrary\t\t\t\t|\n");
    printf("+-------------------------------------------------------+\n");

    int input;

    do {
        printf("\noptions : \n");
        printf("1. Add Borrowing \n");
        printf("2. Get Borrowing \n");
        printf("3. List Borrowing \n");
        printf("4. Return Book \n");
        printf("5. Delete Borrowing \n");
        printf("0. exit \n");

        printf("input : "); scanf("%i", &input);

        switch (input) {
        case 1:
            AddBorrowingHandler(library, borrowing_list);
            break;
        case 2:
            GetBorrowingHandler(library, borrowing_list);
            break;
        case 3:
            ListBorrowingHandler(borrowing_list);
            break;
        case 4:
            ReturnBorrowingHandler(borrowing_list);
            break;
        case 5:
            DeleteBorrowingHandler(borrowing_list);
            break;
        case 0:
            printf("exit \n");
            break;
        default:
            printf("input not found \n");
            break;
        }
    } while (input != 0);
}