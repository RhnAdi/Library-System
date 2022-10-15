#include <stdio.h>
#include "../../../models/library/library.h"
#include "../../../models/book/book.h"
#include "../../../service/library/get.h"
#include <string.h>

void GetBookHandler(struct Library *lib){
    char id[10];

    system("clear");
    printf("+--------------------------------------------------+ \n"); 
    printf("!\t\tGet Book From Library\t\t   !\n");
    printf("+--------------------------------------------------+ \n");    

    printf("input id book : "); scanf("%s", id);

    char error[20];
    struct Book *book = GetBook(lib, id, error);
    if (strlen(error) > 0){
        printf("Warning : %s \n", error);
        return;
    }

    printf("\n+------------------------------------------+\n"); 
    printf("!\t\tDetail Book\t\t   !\n");
    printf("+------------------------------------------+\n"); 
    printf("! id : %s \n", book->ID);
    printf("! title : %s \n", book->Title);
    printf("! description : %s \n", book->Description);
    printf("! author : %s \n", book->Author);
    printf("! publisher : %s \n", book->Publisher);
    printf("! year : %i \n", book->Year);
    printf("! page count : %i \n", book->CountPage);
    printf("! quantity : %i \n", book->Quantity);
    printf("! borrowed : %i \n", book->Borrowed);
    printf("+------------------------------------------+\n");

    return;
}