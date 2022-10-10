#include "./models/borrowing_list/borrowing_list.h"
#include "./models/mahasiswa/mahasiswa.h"
#include "./models/library/library.h"
#include "./models/book/book.h"
#include "./service/borrowing_list/borrowing_list.h"
#include "./service/library/library.h"
#include "./handler/library/library_handler.h"
#include <stdio.h>
#include <stdlib.h>

void main(){
    struct Library lib = initLibrary();
    LibraryHandler(&lib);
}