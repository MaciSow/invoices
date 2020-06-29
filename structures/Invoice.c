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

void showInvoice(struct Invoice *invoice) {
    printf("\n\nInvoice nr: %s:\t", invoice->documentNumber);
    printf("\n%s\n%f\n%f\n%f\n",
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
    } else {
        struct Ware *current = invoice->wHead;

        do {
            showWare(current);
            current = current->wNext;
        } while (current != NULL);
    }
}

void addWare(struct Invoice *invoice, struct Ware *ware) {

    if (invoice->wHead == NULL) {
        invoice->wHead = ware;
    } else {
        struct Ware *current = invoice->wHead;

        while (current->wNext != NULL) {
            current = current->wNext;
        }

        current->wNext = ware;
        current->wNext->wNext = NULL;
    }
}
