#include "./models/borrowing_list/borrowing_list.h"
#include "./models/mahasiswa/mahasiswa.h"
#include "./models/library/library.h"
#include "./models/book/book.h"
#include "./handler/library/library_handler.h"
#include "./handler/borrowing/borrowing_handler.h"
#include <stdio.h>
#include <stdlib.h>

void main(){
    struct Library lib = initLibrary();
    struct BorrowingList borrowing_list = initBorrowingList();
    int input;
    system("clear");
    printf("+-----------------------------------------------+\n");
    printf("|\t\tProgram Library\t\t\t|\n");
    printf("+-----------------------------------------------+\n");
    do {
        printf("option : \n");
        printf("1. Library \n");
        printf("2. Borrowing \n");
        printf("0. exit \n");
        printf("\n input : "); scanf("%i", &input);
        switch (input) {
            case 1:
                LibraryHandler(&lib);
                break;
            case 2:
                BorrowingHandler(&lib, &borrowing_list);
            case 0:
                printf("exit of program \n");
                break;
            default:
                printf("input not found \n");
                break;
        }
    } while (input != 0);
}