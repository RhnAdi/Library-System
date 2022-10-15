#include "../../../models/library/library.h"
#include <stdio.h>
#include <string.h>

void GetAllHandler(struct Library *library) {
    printf("+-------------------------------------------------------------------------+\n");
    printf("|\t\t\t\tLibrary\t\t\t\t          |\n");
    printf("+-------------------------------------------------------------------------+\n");
    if (library->count == 0) {
        printf("|\t\t\t\tno data\t\t\t\t \n");
        printf("+-------------------------------------------------------------------------+\n");
        return;
    }
    for (int i = 0; i < library->count; i++){
        printf("| ID : %s \n", library->books[i].ID);
        printf("| Title : %s \n", library->books[i].Title);
        printf("| Quantity : %i \n", library->books[i].Quantity);
        printf("+-------------------------------------------------------------------------+\n");
    };
}