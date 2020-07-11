#include <stdio.h>
#include <stdlib.h>
#include "Address.h"
#include "Person.h"
#include "Ware.h"
#include "Invoice.h"
#include "InvoiceBox.h"
#include "Input.h"

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
    printf("Invoice's List\n------------------------\n");
    if (invoiceList == NULL) {
        printf("List is empty");
        return;
    }

    int counter = 1;
    struct Invoice *tmp = invoiceList;

    do {
        printf("[ %2i ] - %s\n", counter, tmp->documentNumber);

        tmp = tmp->iNext;
        counter++;
    } while (tmp != NULL);
    printf("------------------------\n");
}

struct Invoice *selectInvoice(struct Invoice *invoiceList) {
    printf("Get item number: ");

    int length = lengthInvoiceList(invoiceList);
    int choose = repeatUntilSelectValid(length);

    int counter = 1;

    struct Invoice *tmp = invoiceList;
    while (counter != choose) {
        tmp = tmp->iNext;
        counter++;
    }
    return tmp;
}

void deleteInvoiceFromList(struct Invoice *invoiceList, struct Invoice *invoice) {

    if (invoice->iNext == NULL && invoice == invoiceList) {
        invoiceList = NULL;
        deleteInvoice(invoice);
        return;
    }

    if (invoice == invoiceList) {
        invoiceList = invoice->iNext;
        deleteInvoice(invoice);
        return;
    }

    struct Invoice *tmp = invoiceList;

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

void invoiceOptions(struct Invoice *invoiceList, struct Invoice *invoice) {
    printf("\nWhat next?\n "
           "[1] Edit\n "
           "[2] Delete\n "
           "[3] Back\n"
           "Your choice:");

    int select = repeatUntilSelectValid(3);

    switch (select) {
        case 1 :
            invoiceEditOptions(invoice);
            break;
        case 2:
            deleteInvoiceFromList(invoiceList, invoice);
            break;
        default:
            break;
    }
}

void invoiceEditOptions(struct Invoice *invoice) {
    int isClose = 0;

    while (!isClose) {
        printf("\nWhat part of invoice edit?\n [1] Invoice data\n [2] Solder data\n [3] Solder address\n "
               "[4] Buyer data\n [5] Buyer address\n [6] Ware data\n [7] Add ware\n [8] Back\n"
               "Your choice:");

        int select = repeatUntilSelectValid(8);

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
                printf("\nEdit wares:\n");
                showWareList(invoice);
                struct Ware *selectedWare = selectWare(invoice);
                wareOptions(invoice,selectedWare);
                calculateSumWares(invoice);
                break;
            case 7:
                printf("\nAdd ware:\n");
                struct Ware *ware = createWare();
                getDataWare(ware);
                calculateValuesWare(ware);
                addWare(invoice,ware);
                calculateSumWares(invoice);
                break;
            default:
                isClose = 1;
                break;
        }
        if (!isClose) {
            printf("\nEdited successful");
            showInvoice(invoice);
        }
    }
}