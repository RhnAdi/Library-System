#include "../../../models/borrowing_list/borrowing_list.h"
#include "../../../models/borrowing/borrowing.h"
#include "../../../models/library/library.h"

#include "../../../service/borrowing_list/get.h"
#include <stdio.h>
#include <string.h>

void GetBorrowingHandler(struct Library *library, struct BorrowingList *borrowing_list) {
    printf("+-------------------------------------------+\n");
    printf("| \t\tGet Borrowing\t\t    |\n");
    printf("+-------------------------------------------+\n");

    char error[20] = {};
    int borrowing_nomor;

    printf("input nomor borrowing : "); scanf("%i", &borrowing_nomor);

    struct Borrowing br = GetBorrowing(borrowing_list, borrowing_nomor, error);
    if (strlen(error) > 0) {
        printf("warning : %s \n", error);
        return;
    }

    printf("| Nomor : %i \n", borrowing_nomor);
    printf("| --- Book Information --- \n");
    printf("| ID : %s \n", br.book->ID);
    printf("| Title : %s \n", br.book->Title);
    printf("| --- Mahasiswa Information --- \n");
    printf("| NIM : %i \n", br.mahasiswa.NIM);
    printf("| Name : %s", br.mahasiswa.Name);
    printf("| Study Program : %s", br.mahasiswa.StudyProgram);
    printf("| Address : %s", br.mahasiswa.Address);
    printf("| Phone Number : %s", br.mahasiswa.PhoneNumber);
    printf("| ----------------------------------------- | \n");
    printf("| Late Charge : Rp. %i \n", br.late_charge);
    printf("| Deadline : %i - %i - %i \n", br.deadline.day, br.deadline.month, br.deadline.year + 1900);
    printf("+-------------------------------------------+\n");

    return;
}