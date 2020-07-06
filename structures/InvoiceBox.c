#include <stdio.h>
#include <stdlib.h>
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

    do {
        showInvoice(invoiceList);

        invoiceList = invoiceList->iNext;
    } while (invoiceList != NULL);
}

void showShortInvoiceList(struct Invoice *invoiceList) {
    printf("Invoice's List\n------------------------\n");
    if (invoiceList == NULL) {
        printf("List is empty");
        return;
    }
    int counter = 1;

    do {
        printf("[ %2i ] - %s\n", counter, invoiceList->documentNumber);

        invoiceList = invoiceList->iNext;
        counter++;
    } while (invoiceList != NULL);
    printf("\n------------------------\n");
}

struct Invoice *selectInvoice(struct Invoice *invoiceList) {
    printf("\nGet item number: ");

    int length = lengthInvoiceList(invoiceList);
    int choose = repeatUntilSelectValid(length);

    int counter = 1;

    while (counter != choose) {
        invoiceList = invoiceList->iNext;
        counter++;
    }
    return invoiceList;
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

    do {
        invoiceList = invoiceList->iNext;
        counter++;
    } while (invoiceList != NULL);

    return counter;
}

void invoiceOptions(struct Invoice *invoiceList, struct Invoice *invoice) {


    printf("\nWhat next?\n [1] Edit\n [2] Delete\n [3] Back\nYour choice:");

    int select = repeatUntilSelectValid(3);

    switch (select) {
        case 1 :
            break;
        case 2:
            deleteInvoiceFromList(invoiceList, invoice);
            break;
        case 3:
            break;
        default:
            break;
    }
}