#include "../../models/borrowing_list/borrowing_list.h"
#include "../../models/borrowing/borrowing.h"
#include "../../models/mahasiswa/mahasiswa.h"
#include "../../models/library/library.h"
#include "../../models/time/time.h"
#include "../../error/error.h"
#include <string.h>
#include <time.h>

struct Borrowing AddBorrowing(
    struct Library *library, 
    struct BorrowingList *borrowing_list, 
    struct Mahasiswa mahasiswa,
    char *id, 
    char *error
) {
    for (int i = 0; i <= library->count; i++ ) {
        int result = strcmp(id, library->books[i].ID);
        if (result == 0) {
            if (borrowing_list->count == 0) {
                struct Borrowing b;
                
                library->books[i].Borrowed++;
                b.book = library->books[i];

                time_t t = time(NULL);
                t += 604800;
                struct tm now = *localtime(&t);
                struct Time deadline;
                deadline.day = now.tm_mday;
                deadline.month = now.tm_mon;
                deadline.year = now.tm_year;

                b.deadline = deadline;
                b.mahasiswa = mahasiswa;
                b.late_charge = 0;

                borrowing_list->list[0] = b;

                return borrowing_list->list[0]; 
            } else {
                library->books[i].Borrowed++;
                borrowing_list->list[borrowing_list->count].book = library->books[i];

                time_t t = time(NULL);
                struct tm now = *localtime(&t);
                struct tm date = { .tm_mday = now.tm_mday + 7, .tm_mon = now.tm_mon, .tm_year = now.tm_year };
                struct Time deadline;
                deadline.day = date.tm_mday;
                deadline.month = date.tm_mon;
                deadline.year = date.tm_year;

                struct Borrowing b;

                b.deadline = deadline;
                b.mahasiswa = mahasiswa;
                b.late_charge = 0;

                borrowing_list->list[borrowing_list->count] = b;

                return borrowing_list->list[borrowing_list->count];
            }
        } else {
            strcpy(error, BOOK_NOT_FOUND);
        }
    };
}