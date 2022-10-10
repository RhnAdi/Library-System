#include "../book/book.h"
#include "../mahasiswa/mahasiswa.h"
#include "../time/time.h"

struct Borrowing {
    struct Book book;
    struct Mahasiswa mahasiswa;
    struct Time deadline;
    int late_charge;
};

struct Borrowing initBorrowing(
    struct Book book,
    struct Mahasiswa mahasiswa,
    struct Time deadline
) {
    struct Borrowing b = { book, mahasiswa, deadline, 0 };
    return b;
}