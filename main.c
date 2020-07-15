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
    struct Invoice *invoiceList;
    invoiceList = NULL;

    readDataFromFile(&invoiceList);

//    tests


//    readDate();

//    return 0;


    int isClose = 0;

    while (!isClose) {
        ////MENU////
        printSeparator(48, '=');
        printf("%26s\n", "MENU");
        printSeparator(48, '-');
        printf("[1] Show Invoices List\n");
        printf("[2] Issuing Invoice\n");
        printf("[3] Search Invoice By Date\n");
        printf("[4] Show Unpaid Invoices\n");
        printf("[5] Exit\n");
        printSeparator(48, '-');
        printf("Your choice:");
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
    saveDataToFile(&invoiceList);
    return 0;
}

// todo * zapis do pliku
// todo * sprzątanie
// todo * doxygen