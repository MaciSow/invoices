#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
// todo: make a structures



int main() {
    printf("Hello, World!\n");

    char* string;
    FILE *ptr;
    // todo: add invoice variables


    if ((ptr = fopen("C:\\Users\\macie\\Desktop\\invoice\\invoice.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    while((string= fgetc(ptr)) != EOF){
        printf("%c", string);

        // todo: assign file values to variables
    }

    fclose(ptr);
    return 0;
}

