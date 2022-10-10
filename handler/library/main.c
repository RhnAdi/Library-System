#include "add/add.h"
#include "get/get.h"
#include <stdio.h>
#include "../../models/library/library.h"

void LibraryHandler(struct Library *lib){
    AddBookHandler(lib);
    GetBookHandler(lib);
}