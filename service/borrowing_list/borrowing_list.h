#include "../../models/borrowing_list/borrowing_list.h"
#include "../../models/mahasiswa/mahasiswa.h"
#include "../../models/library/library.h"
#include <stdbool.h>
#include "get.c"
#include "add.c"

struct Borrowing AddBorrowing(
    struct Library *library, 
    struct BorrowingList *borrowing_list, 
    struct Mahasiswa mahasiswa,
    char *id, 
    char *error
);

struct Borrowing GetBorrowing(struct BorrowingList *borrowing_list, int id, char *error);
bool DeleteBorrowing(struct BorrowingList *borrowing_list, int id, char *error);
struct Borrowing ReturnBorrowing(struct BorrowingList *borrowing_list, int id, char *error);