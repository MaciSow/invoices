#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures/Person.h"
#include "structures/Ware.h"
#include "structures/Invoice.h"
#include "structures/Address.h"
#include "functions/input.h"
#include "structures/InvoiceBox.h"
#include "functions/utilities.h"
#include "functions/output.h"

int main() {


//    return 0;

    const char *PATH = "";
    char fileName[] = "invoice.txt";

    struct Invoice *invoiceList;
    invoiceList = NULL;

    readDataFromFile(&invoiceList, PATH, fileName);
//    tests
//    saveDataToFile(&invoiceList, PATH, fileName);

//    readDate();

//    return 0;


    int isClose = 0;

    while (!isClose) {
        ////MENU////
        printMenu();

        int choose = readSelectOption(1, 5);
        printSeparator(48, '=');
        printf("\n");
        char *date;

        switch (choose) {
            case 1:
                showShortInvoiceList(invoiceList);
                if (invoiceList == NULL) {
                    break;
                }
                struct Invoice *selectedInvoice = selectInvoice(invoiceList);
                showInvoice(selectedInvoice);
                invoiceOptions(&invoiceList, selectedInvoice);
                break;
            case 2:
                issuingInvoice(&invoiceList);
                break;
            case 3:
                date = readDate();
                searchInvoicesByDate(&invoiceList, date);
                free(date);
                break;
            case 4:
                searchInvoicesByPaid(&invoiceList);
                break;
            default:
                isClose = 1;
                break;
        }
        printf("\n\n");
    }

//    printf("Do you want overwrite file [Y/n]:");
//    char *str = readLine(2);
//    char choose = (char) str[0];
//    free(str);

//    if (!(choose == '\n' || choose == 'Y' || choose == 'y')) {
//        strcpy(fileName, "final.txt");
//    }

//    saveDataToFile(&invoiceList, PATH, fileName);

    //function
    struct Invoice *tmp;

    while (invoiceList!=NULL) {
        tmp = invoiceList->iNext;

        deleteInvoice(invoiceList);
        invoiceList = tmp;
    }

    //end function
    return 0;
}

// todo * sprzątanie
// todo * doxygen