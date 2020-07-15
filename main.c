#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures/Person.h"
#include "structures/Ware.h"
#include "structures/Invoice.h"
#include "structures/Address.h"
#include "functions/input.h"
#include "structures/InvoiceBox.h"
#include "functions/utilities.h"
#include "functions/output.h"

int main() {
    const char *PATH = "C:\\Users\\macie\\Desktop\\invoice\\";
    char fileName[] = "invoice.txt";

    struct Invoice *invoiceList;
    invoiceList = NULL;

    readDataFromFile(&invoiceList, PATH, fileName);
//    tests


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

    printf("Do you want overwrite file [Y/n]:");
    char choose = (char) readLine(2)[0];

    if (!(choose == '\n' || choose == 'Y' || choose == 'y')) {
        strcpy(fileName, "final.txt");
    }

    saveDataToFile(&invoiceList, PATH, fileName);
    return 0;
}

// todo * sprzątanie
// todo * doxygen