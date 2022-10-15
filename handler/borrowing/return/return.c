#include "../../../models/borrowing_list/borrowing_list.h"
#include "../../../service/borrowing_list/return.h"
#include "../../../models/borrowing/borrowing.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void ReturnBorrowingHandler(struct BorrowingList *borrowing_list) {
    printf("+-----------------------------------------+\n");
    printf("| \t\tReturn Book\t\t |\n");
    printf("+-----------------------------------------+\n");

    int borrowing_number;
    char error[20] = {};

    printf("input borrowing number : "); scanf("%i", &borrowing_number);

    struct Borrowing br = ReturnBorrowing(borrowing_list, borrowing_number, error);
    if (strlen(error) > 0) {
        printf("warning : %s \n", error);
        return;
    }

    system("clear");
    printf("+-----------------------------------------+\n");
    printf("| \t\tReturned Book\t\t|\n");
    printf("+-----------------------------------------+\n");
    printf("| Name : %s", br.mahasiswa.Name);
    printf("| NIM : %i \n", br.mahasiswa.NIM);
    printf("| Study Program : %s", br.mahasiswa.StudyProgram);
    printf("| Address : %s", br.mahasiswa.Address);
    printf("| Phone Number : %s", br.mahasiswa.PhoneNumber);
    printf("+-----------------------------------------+\n");
    printf("| Book ID : %s \n", br.book->ID);
    printf("| Book Title : %s \n", br.book->Title);
    printf("+-----------------------------------------+\n");
    printf("| Late Charge : Rp. %i \n", br.late_charge);
    printf("| Deadline : %i - %i -%i \n", br.deadline.day, br.deadline.month, br.deadline.year);
    printf("+-----------------------------------------+\n");

    return;

}

