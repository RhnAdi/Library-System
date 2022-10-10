#include <stdio.h>
#include <stdlib.h>
#include "../book/book.h"

struct Library {
    struct Book books[100];
    int count;
};

struct Library initLibrary() {
    struct Library lib;
    lib.count = 0;
    return lib;
};