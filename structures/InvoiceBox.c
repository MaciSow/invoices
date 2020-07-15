#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Address.h"
#include "Person.h"
#include "Ware.h"
#include "Invoice.h"
#include "InvoiceBox.h"
#include "../functions/utilities.h"
#include "../functions/input.h"
#include "../functions/output.h"


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

    struct Invoice *tmp = invoiceList;

    do {
        showInvoice(tmp);

        tmp = tmp->iNext;
    } while (tmp != NULL);
}

void showShortInvoiceList(struct Invoice *invoiceList) {
    printf("Invoice's List\n");
    printSeparator(100, '-');

    if (invoiceList == NULL) {
        printf("List is empty\n");
        printSeparator(100, '-');
        return;
    }

    int counter = 1;
    struct Invoice *tmp = invoiceList;

    do {
        printf("[ %2i ] - %s\n", counter, tmp->documentNumber);

        tmp = tmp->iNext;
        counter++;
    } while (tmp != NULL);

    printSeparator(100, '-');
}

struct Invoice *selectInvoice(struct Invoice *invoiceList) {
    printf("Get item number:");

    int length = lengthInvoiceList(invoiceList);
    int choose = readSelectOption(1, length);

    int counter = 1;

    struct Invoice *tmp = invoiceList;
    while (counter != choose) {
        tmp = tmp->iNext;
        counter++;
    }
    return tmp;
}

void deleteInvoiceFromList(struct Invoice **invoiceList, struct Invoice *invoice) {

    if (invoice->iNext == NULL && invoice == *invoiceList) {
        *invoiceList = NULL;
        deleteInvoice(invoice);
        return;
    }

    if (invoice == *invoiceList) {
        deleteInvoice(invoice);
        *invoiceList = invoice->iNext;
        return;
    }

    struct Invoice *tmp = *invoiceList;

    if (invoice->iNext == NULL) {

        while (tmp) {
            if (tmp->iNext == invoice) {
                tmp->iNext = NULL;
                deleteInvoice(invoice);
                return;
            }
            tmp = tmp->iNext;
        }
    }

    while (tmp) {
        if (tmp->iNext == invoice) {
            tmp->iNext = invoice->iNext;
            deleteInvoice(invoice);
            return;
        }
        tmp = tmp->iNext;
    }
}

int lengthInvoiceList(struct Invoice *invoiceList) {
    if (invoiceList == NULL) {
        return 0;
    }

    int counter = 0;
    struct Invoice *tmp = invoiceList;

    do {
        tmp = tmp->iNext;
        counter++;
    } while (tmp != NULL);

    return counter;
}

void invoiceOptions(struct Invoice **invoiceList, struct Invoice *invoice) {
    int isClose = 0;

    while (!isClose) {
        printf("\nWhat next?\n "
               "[1] Edit\n "
               "[2] Delete\n "
               "[3] Back\n"
               "Your choice:");

        int select = readSelectOption(1, 3);

        switch (select) {
            case 1 :
                invoiceEditOptions(invoice);
                break;
            case 2:
                deleteInvoiceFromList(invoiceList, invoice);
                printf("\nDeleted successfully");
            default:
                isClose = 1;
                break;
        }
    }
}

void invoiceEditOptions(struct Invoice *invoice) {
    int isClose = 0;
    int hasWares;

    while (!isClose) {
        hasWares = invoice->wHead == NULL ? 0 : 1;

        printf("\nWhat part of invoice edit?\n"
               " [1] Invoice data\n"
               " [2] Solder data\n"
               " [3] Solder address\n"
               " [4] Buyer data\n"
               " [5] Buyer address\n"
               " [6] Add ware\n");

        if (hasWares) {
            printf(" [7] Edit wares\n"
                   " [8] Back\n");
        } else {
            printf(" [7] Back\n");
        }

        printf("Your choice:");

        int select = readSelectOption(1, hasWares ? 8 : 7);

        switch (select) {
            case 1 :
                printf("\nEdit invoice data:\n");
                editInvoice(invoice);
                break;
            case 2:
                printf("\nEdit solder data:\n");
                editPerson(invoice->solder, 1);
                break;
            case 3:
                printf("\nEdit solder address:\n");
                editAddress(invoice->solder->address);
                break;
            case 4 :
                printf("\nEdit buyer data:\n");
                editPerson(invoice->buyer, 0);
                break;
            case 5:
                printf("\nEdit buyer address:\n");
                editAddress(invoice->buyer->address);
                break;
            case 6:
                printf("\nAdd ware:\n");
                struct Ware *ware = createWare();
                getDataWare(ware);
                calculateValuesWare(ware);
                addWare(invoice, ware);
                calculateSumWares(invoice);
                break;
            case 7:
                if (!hasWares) {
                    isClose = 1;
                    break;
                }
                printf("\nEdit wares:\n");
                showWareList(invoice);
                struct Ware *selectedWare = selectWare(invoice);
                wareOptions(invoice, selectedWare);
                calculateSumWares(invoice);
                break;
            default:
                isClose = 1;
                break;
        }
        if (!isClose) {
            printf("\nEdited successfully");
        }
        showInvoice(invoice);
    }
}

void searchInvoicesByDate(struct Invoice **invoiceList, char date[]) {
    if (*invoiceList == NULL) {
        printf("List is empty");
        return;
    }

    int length = 0;
    struct Invoice *tmp = *invoiceList;
    while (tmp) {
        if (!strcmp(tmp->date, date)) {
            length++;
        }
        tmp = tmp->iNext;
    }

    if (!length) {
        printf("No results found");
        return;
    }

    struct Invoice *tab[length];

    int index = 0;
    tmp = *invoiceList;
    while (tmp) {
        if (!strcmp(tmp->date, date)) {
            tab[index] = tmp;
            index++;
        }
        tmp = tmp->iNext;
    }

    printf("Invoice's List\n");
    printSeparator(100, '-');

    for (int i = 1; i <= length; ++i) {
        printf("[ %2i ] - %s\n", i, tab[i - 1]->documentNumber);
    }

    printSeparator(100, '-');
    printf("Get item number:");

    int choose = readSelectOption(1, length) - 1;
    showInvoice(tab[choose]);
    invoiceOptions(&*invoiceList, tab[choose]);
}

int searchInvoicesByPaid(struct Invoice **invoiceList) {
    if (*invoiceList == NULL) {
        printf("List is empty");
        return 0;
    }

    int length = 0;
    struct Invoice *tmp = *invoiceList;

    while (tmp) {
        if (tmp->paid < tmp->grossSum) {
            length++;
        }
        tmp = tmp->iNext;
    }

    if (!length) {
        printf("No results found");
        return 0;
    }

    struct Invoice *tab[length];

    int index = 0;
    tmp = *invoiceList;

    while (tmp) {
        if (tmp->paid < tmp->grossSum) {
            tab[index] = tmp;
            index++;
        }
        tmp = tmp->iNext;
    }


    printf("Invoice's List\n");
    printSeparator(100, '-');

    for (int i = 0; i < length; ++i) {
        printf("[ %2i ] - %s\n", i + 1, tab[i]->documentNumber);
        showPersonsInLine(tab[i]->solder, tab[i]->buyer);
        printf("To paid: %.2f\n", tab[i]->grossSum - tab[i]->paid);

        if (i < length - 1) {
            printf("\n");
        }
    }

    printSeparator(100, '-');
    printf("Which invoice do you want to paid (press 0 to back):");

    int choose = readSelectOption(0, length);

    if (choose == 0) {
        return 0;
    }
    choose--;
    showInvoiceToPaid(tab[choose]);

    return 1;
}
