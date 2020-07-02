#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"
#include "Ware.h"
#include "Invoice.h"


struct Invoice
createInvoice(char documentNumber[10], char date[20], float netSum, float taxSum, float grossSum, struct Person *solder,
              struct Person *buyer) {

    struct Invoice invoice;

    strcpy(invoice.documentNumber, documentNumber);
    strcpy(invoice.date, date);
    invoice.netSum = netSum;
    invoice.netSum = netSum;
    invoice.taxSum = taxSum;
    invoice.grossSum = grossSum;
    invoice.solder = solder;
    invoice.buyer = buyer;
    invoice.wHead = (struct Ware *) malloc(sizeof(struct Ware));
    invoice.wHead = NULL;

    return invoice;
}

struct Invoice createEmptyInvoice() {

    struct Invoice invoice;

    strcpy(invoice.documentNumber, "--");
    strcpy(invoice.date, "--");
    invoice.netSum = 0;
    invoice.netSum = 0;
    invoice.taxSum = 0;
    invoice.grossSum = 0;
    invoice.solder = NULL;
    invoice.buyer = NULL;
    invoice.wHead = (struct Ware *) malloc(sizeof(struct Ware));
    invoice.wHead = NULL;

    return invoice;
}


void showInvoice(struct Invoice *invoice) {
    printf("\n\nInvoice nr: %s:\t", invoice->documentNumber);
    printf("\n%s\n%f\n%f\n%f",
           invoice->date,
           invoice->netSum,
           invoice->taxSum,
           invoice->grossSum
    );

    printf("\n\nSolder:\n");
    showPerson(invoice->solder);

    printf("\n\nBuyer:\n");
    showPerson(invoice->buyer);

    printf("\n\nWeres:\n");

    if (invoice->wHead == NULL) {
        printf("List is empty");
        return;
    }

    do {
        showWare(invoice->wHead);
        invoice->wHead = invoice->wHead->wNext;
    } while (invoice->wHead != NULL);
}

void addWare(struct Invoice *invoice, struct Ware *ware) {

    if (invoice->wHead == NULL) {
        invoice->wHead = ware;
        invoice->wHead->wNext = NULL;
    } else {
        struct Ware *current = invoice->wHead;

        while (current->wNext != NULL) {
            current = current->wNext;
        }

        current->wNext = ware;
        current->wNext->wNext = NULL;
    }
}
