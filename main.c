#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures/Person.h"
#include "structures/Ware.h"
#include "structures/Invoice.h"
#include "structures/Address.h"
#include "structures/Input.h"
#include "structures/InvoiceBox.h"
#include "structures/utilities.h"

int main() {
    struct Invoice *invoiceList;
    invoiceList = NULL;

    readData(&invoiceList);

//    tests


//    getDate();

// return 0;


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
        int choose = repeatUntilSelectValid(1, 5);
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
                date = getDate();
                searchInvoicesByDate(invoiceList, date);
                free(date);
                break;
            case 4:
                break;
            default:
                isClose = 1;
                break;
        }
        printf("\n\n");
    }








    // while (searchInvoicesByPaid(invoiceList));

//    printf("%d", strcmp("11.07.2020","11.07.2020"));
    // printf("%s", generateUniqueID(invoiceList));
//    issuingInvoice(&invoiceList);

// funkcja
//    showShortInvoiceList(invoiceList);
//    struct Invoice *selectedInvoice = selectInvoice(invoiceList);
//    showInvoice(selectedInvoice);
//    invoiceOptions(invoiceList, selectedInvoice);

//    selectedInvoice = selectInvoice(invoiceList);
//    showInvoice(selectedInvoice);
//    invoiceOptions(invoiceList, selectedInvoice);
///  end funkcja

    return 0;
}

// todo * menu użytkownika
// todo * zapis do pliku
// todo * sprzątanie
// todo * doxygen