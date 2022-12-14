#include <stdio.h>
#include "../../../models/library/library.h"
#include "../../../models/book/book.h"
#include "../../../service/library/add.h"
#include <string.h>

void AddBookHandler(struct Library *lib) {
    system("clear");
    printf("+-------------------------------------------------+ \n");
    printf("!\t\tAdd Book To Library\t\t  !\n");
    printf("+-------------------------------------------------+ \n");

    struct Book req;
    printf("input id : "); scanf("%s", req.ID);
    printf("input title : "); scanf("%s", req.Title);
    printf("input description : "); scanf("%s", req.Description);
    printf("input publisher : "); scanf("%s", req.Publisher);
    printf("input author : "); scanf("%s", req.Author);
    printf("input year : "); scanf("%i", &req.Year);
    printf("input count page : "); scanf("%i", &req.CountPage);
    printf("input quantity : "); scanf("%i", &req.Quantity);

    char error[20];
    struct Book result = AddBook(lib, req, error);
    if (strlen(error) > 0){
        printf("error -> %s \n", error);
    } 
}