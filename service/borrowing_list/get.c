#include "../../models/borrowing_list/borrowing_list.h"
#include "../../models/borrowing/borrowing.h"
#include "../../models/time/time.h"
#include "../../error/error.h"
#include "../../setting.h"
#include <string.h>
#include <time.h>

struct Borrowing GetBorrowing(struct BorrowingList *borrowing_list, int id, char *error){
    if (id - 1 <= borrowing_list->count ) {
        
        time_t t = time(NULL);
        struct tm now = *localtime(&t);

        struct Time deadline = borrowing_list->list[id-1].deadline;
        if (now.tm_mday > deadline.day) {
            int number_of_days_late = now.tm_mday - deadline.day;
            borrowing_list->list[id-1].late_charge = number_of_days_late * LATE_CHARGE;
        }

        return borrowing_list->list[id-1];
    }

    strcpy(error, BORROWING_NOT_FOUND);
};