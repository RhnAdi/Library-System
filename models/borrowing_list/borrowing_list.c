#include "../borrowing/borrowing.h"

struct BorrowingList {
    struct Borrowing list[100];
    int count;
};

struct BorrowingList initBorrowingList() {
    struct BorrowingList list;
    list.count = 0;
    return list;
};