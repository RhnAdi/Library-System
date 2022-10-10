#include <stdio.h>
#include "../../../models/library/library.h"
#include "../../../models/book/book.h"
#include "../../../service/library/library.h"
#include <string.h>

void GetBookHandler(struct Library *lib){
    char id[10];

    system("clear");
    printf("\t \033[0;34m Get Book From Library \033[0;30m \n");
    printf("-------------------------------------------------- \n");    

    printf("input id book : "); scanf("%s", id);

    char error[20];
    struct Book book = GetBook(lib, id, error);
    if (strlen(error) > 0){
        printf("error -> %s \n", error);
        return;
    }

    printf("\t   Detail Book \n");
    printf("-------------------------------------------------- \n"); 
    printf("id : %s \n", book.ID);
    printf("title : %s \n", book.Title);
    printf("description : %s \n", book.Description);
    printf("author : %s \n", book.Author);
    printf("publisher : %s \n", book.Publisher);
    printf("year : %i \n", book.Year);
    printf("page count : %i \n", book.CountPage);
    printf("quantity : %i \n", book.Quantity);
    printf("borrowed : %i \n", book.Borrowed);

    return;
}