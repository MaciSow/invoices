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
    const char *PATH = "";                 //ŚCIEŻKA DO PLIKU
    char fileName[100] = "invoices.txt";   //NAZWA PLIKU WEJŚCIOWEGO

    struct Invoice *invoiceList;
    invoiceList = NULL;

    readDataFromFile(&invoiceList, PATH, fileName);

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
                showInvoiceList(invoiceList);
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


    if (!readYesOrNoOption("Do you want overwrite file")) {
        strcpy(fileName, "update_invoice.txt");    //NAZWA NOWEGO PLIKU WYJŚCIOWEGO
    }

    saveDataToFile(invoiceList, PATH, fileName);

    deleteInvoiceList(&invoiceList);
    return 0;
}