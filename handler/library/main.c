#include "add/add.h"
#include "get/get.h"
#include "delete/delete.h"
#include "list/list.h"
#include <stdio.h>
#include "update/update.h"
#include "../../models/library/library.h"

void LibraryHandler(struct Library *lib){
    int input;
    do {
        printf("option : \n");
        printf("1. list book \n");
        printf("2. add book \n");
        printf("3. get detail book \n");
        printf("4. update book \n");
        printf("5. delete book \n");
        printf("0. exit \n");
        printf("\ninput : "); scanf("%i", &input);
        switch (input) {
            case 1:
                GetAllHandler(lib);
                break;
            case 2:
                AddBookHandler(lib);
                break;
            case 3:
                GetBookHandler(lib);
                break;
            case 4:
                UpdateBookHandler(lib);
                break;
            case 5:
                DeleteBookHandler(lib);
                break;
            case 0:
                printf("exit \n");
                break;
            default:
                printf("option not found \n");
                break;
        }
    } while (input != 0);
}