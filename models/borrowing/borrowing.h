#ifndef BORROWING_H
#define BORROWING_H
#include "borrowing.c"

struct Borrowing;

struct Borrowing initBorrowing(
    struct Book book,
    struct Mahasiswa mahasiswa,
    struct Time deadline
);

#endif