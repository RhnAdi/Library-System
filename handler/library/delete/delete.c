#include "../../../models/library/library.h"
#include "../../../service/library/delete.h"
#include <stdbool.h>

void DeleteBookHandler(struct Library *library) {
    char id[10], error[20];

    printf("+-----------------------------------------+\n");
    printf("!\t\tDelete Book\t\t  !\n");
    printf("+-----------------------------------------+\n");

    printf("input id : "); scanf("%s", id);

    bool deleted = DeleteBook(library, id, error);
    if (strlen(error) > 0){
        printf("Warning : %s \n", error);
        return;
    }

    if (deleted != true) {
        printf("Error : can't delete book\n");
        return;
    }

    printf("success delete book with id : %s \n", id);
    return;
}