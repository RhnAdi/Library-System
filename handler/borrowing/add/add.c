#include "../../../models/borrowing_list/borrowing_list.h"
#include "../../../models/mahasiswa/mahasiswa.h"
#include "../../../models/library/library.h"
#include "../../../models/borrowing/borrowing.h"

#include "../../../service/borrowing_list/add.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void AddBorrowingHandler(struct Library *library, struct BorrowingList *borrowing_list) {
    system("clear");
    char book_id[10];

    printf("+--------------------------------------------------------------+\n");
    printf("|\t\t\tAdd Borrowing\t\t\t       |\n");
    printf("+--------------------------------------------------------------+\n");


    printf("input id book : "); scanf("%s", book_id);

    struct Mahasiswa mhs;
    printf("input nim : "); scanf("%i", &mhs.NIM);

    fgetc(stdin);
    printf("input name : "); fgets(mhs.Name, 20, stdin);
    printf("input study program : "); fgets(mhs.StudyProgram, 20, stdin);
    printf("input phone number : "); fgets(mhs.PhoneNumber, 16, stdin);
    printf("input address : "); fgets(mhs.Address, 30, stdin);

    char error[20] = {};
    struct Borrowing br = AddBorrowing(library, borrowing_list, mhs, book_id, error);
    if (strlen(error) > 0){
        printf("Warning : %s \n", error);
        return;
    }

    printf("add borrowing success \n");
    return;
}