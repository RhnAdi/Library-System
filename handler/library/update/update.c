#include "../../../models/library/library.h"
#include "../../../service/library/update.h"
#include "../../../models/book/book.h"
#include <string.h>
#include <stdio.h>

void UpdateBookHandler(struct Library *library) {
    struct Book req;
    char error[20];

    system("clear");
    printf("+-----------------------------------------+\n");
    printf("!\t\tUpdate Book\t\t  !\n");
    printf("+-----------------------------------------+\n");

    printf("input id : "); scanf("%s", req.ID);
    printf("input title : "); scanf("%s", req.Title);
    printf("input description : "); scanf("%s", req.Description);
    printf("input publisher : "); scanf("%s", req.Publisher);
    printf("input author : "); scanf("%s", req.Author);
    printf("input year : "); scanf("%i", &req.Year);
    printf("input count page : "); scanf("%i", &req.CountPage);
    printf("input quantity : "); scanf("%i", &req.Quantity);

    struct Book updated_book = UpdateBook(library, req, error);
    if (strlen(error) > 0){
        printf("Warning : %s \n", error);
        return;
    }

    printf("success update book in library with id = %s \n", updated_book.ID);
    return;
}