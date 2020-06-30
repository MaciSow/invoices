#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"
#include "Invoice.h"

void readData() {
    //    char* string;
//    FILE *ptr;
//    // todo: add invoice variables
//
//
//    if ((ptr = fopen("C:\\Users\\macie\\Desktop\\invoice\\invoice.txt", "r")) == NULL) {
//        printf("Error! opening file");
//        exit(1);
//    }
//
//    while((string= fgetc(ptr)) != EOF){
//        printf("%c", string);
//
//        // todo: assign file values to variables
//    }
//
//    fclose(ptr);
}

void addInvoice(struct Invoice **invoiceList, struct Invoice *invoice) {
    if (*invoiceList == NULL) {
        *invoiceList = invoice;
        (*invoiceList)->iNext = NULL;
    } else {
        struct Invoice *current = *invoiceList;

        while (current->iNext != NULL) {
            current = current->iNext;
        }

        current->iNext = invoice;
        current->iNext->iNext = NULL;
    }
}

void showInvoiceList(struct Invoice *invoiceList) {
    if (invoiceList == NULL) {
        printf("List is empty");
        return;
    }

    do {
        showInvoice(invoiceList);

        invoiceList = invoiceList->iNext;
    } while (invoiceList != NULL);

}


