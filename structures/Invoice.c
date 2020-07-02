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
    invoice.taxSum = 0;
    invoice.grossSum = 0;
    invoice.solder = NULL;
    invoice.buyer = NULL;
    invoice.wHead = (struct Ware *) malloc(sizeof(struct Ware));
    invoice.wHead = NULL;

    return invoice;
}

void fillInvoice(struct Invoice *invoice, struct Person *solder, struct Person *buyer, char documentNumber[10],
                 char date[20], char paymentDeadline[20], char netSum[15], char taxSum[15], char grossSum[15],
                 char paid[15]) {
    strcpy(invoice->documentNumber, documentNumber);
    strcpy(invoice->date, date);
    strcpy(invoice->paymentDeadline, paymentDeadline);
    invoice->netSum = strtof(netSum, NULL);
    invoice->taxSum = strtof(taxSum, NULL);
    invoice->grossSum = strtof(grossSum, NULL);
    invoice->paid = strtof(paid, NULL);
    invoice->solder = solder;
    invoice->buyer = buyer;
    invoice->wHead = NULL;
};

void showInvoice(struct Invoice *invoice) {
    printf("\n====================================================================================================\n");
    printf("Invoice nr: %-72sDate: %s", invoice->documentNumber, invoice->date);


    printf("\n\nSolder:\n");
    showPerson(invoice->solder);

    printf("\n\nBuyer:\n");
    showPerson(invoice->buyer);
    printf("\n\n----------------------------------------------------------------------------------------------------\n");
    printf("%5s|%14s%10s%10s|%11s|%11s|%11s|%11s|%11s\n", "No.", "Name", "|", "Amount", "Net Price", "Net Val", "Tax",
           "Tax Val", "Gross Val");
    printf("----------------------------------------------------------------------------------------------------\n");
    if (invoice->wHead == NULL) {
        printf("List is empty");
        return;
    }
    int i = 1;
    do {
        showWare(invoice->wHead, i++);
        invoice->wHead = invoice->wHead->wNext;
    } while (invoice->wHead != NULL);
    printf("\n%100s\n", "---------------------------------------");
    printf("%65s%11s|%11s|%11s\n", "Sum:", "Net", "Tax", "Gross");
    printf("%100s\n", "---------------------------------------");

    printf("%76.2f %11.2f %11.2f\n%17s %s\n%17s %s\n%17s %.2f",
           invoice->netSum,
           invoice->taxSum,
           invoice->grossSum,
           "Account Number:",
           formatAccountNumber(invoice->solder->accountNumber),
           "Payment Deadline:",
           invoice->paymentDeadline,
           "Paid:",
           invoice->paid
    );
    printf("\n====================================================================================================\n");
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

char *formatAccountNumber(const char *accountNumber) {
    char *correctFormat = malloc(40);
    memset(correctFormat, 0, 40);

    int index = 0;

    for (int i = 0; i < 26; ++i) {
        correctFormat[index] = accountNumber[i];

        if (i % 4 == 1) {
            index++;
            correctFormat[index] = ' ';
        }
        index++;
    }

    return correctFormat;

}
