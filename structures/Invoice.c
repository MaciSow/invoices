#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"
#include "Ware.h"
#include "Invoice.h"
#include "utilities.h"
#include "Address.h"

struct Invoice *createInvoice() {
    struct Invoice *invoice;
    invoice = (struct Invoice *) malloc(sizeof(struct Invoice));
    strcpy(invoice->documentNumber, strcat(getCurrentDate("%d/%m/%Y"), "/0001"));
    strcpy(invoice->date, getCurrentDate("%d.%m.%Y"));
    invoice->netSum = 0;
    invoice->taxSum = 0;
    invoice->grossSum = 0;
    invoice->wHead = NULL;

    return invoice;
}

void fillInvoice(struct Invoice *invoice, struct Person *solder, struct Person *buyer, char documentNumber[],
                 char date[], char paymentDeadline[], char netSum[], char taxSum[], char grossSum[], char paid[]) {
    strcpy(invoice->documentNumber, cutString(documentNumber, 20));
    strcpy(invoice->date, cutString(date, 20));
    strcpy(invoice->paymentDeadline, cutString(paymentDeadline, 20));
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
    } else {
        int i = 1;
        do {
            showWare(invoice->wHead, i++);
            invoice->wHead = invoice->wHead->wNext;
        } while (invoice->wHead != NULL);
    }

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
           invoice->paid ? invoice->grossSum : 0
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

void getDataInvoice(struct Invoice *invoice) {
    char choose;
    int amountWeeks;

    printf("Is paid? [Y/n]:");
    choose = (char) readLine(2)[0];

    if (choose == '\n' || choose == 'Y' || choose == 'y') {
        invoice->paid = 1;
        amountWeeks = 0;
    } else {
        invoice->paid = 0;
        printf("Payment deadline:\n [1] one week\n [2] two weeks\n [3] four weeks\nYour choice:");

        int isInvalid;

        do {
            isInvalid = 0;
            amountWeeks = strtol(readLine(2), NULL, 10);
            if (!(amountWeeks > 0 && amountWeeks < 4)) {
                isInvalid = 1;
                printf("\nWrong data, try again:");
            }

        } while (isInvalid);

        amountWeeks = amountWeeks == 3 ? 4 : amountWeeks;
    }
    strcpy(invoice->paymentDeadline, getFutureDate("%d.%m.%Y", amountWeeks));

}

void issuingInvoice(struct Invoice **invoiceList) {
    struct Invoice *invoice = createInvoice();
    struct Person *solder = createPerson();
    struct Person *buyer = createPerson();
    struct Address *addressSolder = createAddress();
    struct Address *addressBuyer = createAddress();

    getDataInvoice(invoice);

    getDataPerson(solder, 1);
    getDataAddress(addressSolder);

    getDataPerson(buyer, 0);
    getDataAddress(addressBuyer);

    solder->address = addressSolder;
    invoice->solder = solder;

    buyer->address = addressBuyer;
    invoice->buyer = buyer;

    putWareList(invoice);
    calculateSumWares(invoice);

    addInvoice(invoiceList, invoice);
}

void putWareList(struct Invoice *invoice) {
    int isEnd;
    char choose;

    do {
        printf("\nWare\n");
        isEnd = 0;

        struct Ware *ware = createWare();
        getDataWare(ware);
        calculateValuesWare(ware);
        addWare(invoice, ware);

        printf("\nAdd another ware? [Y/n]:");
        choose = (char) readLine(2)[0];

        if (choose == '\n' || strlwr(&choose)[0] == 'y') {
            isEnd = 1;
        }

    } while (isEnd);
}

void calculateSumWares(struct Invoice *invoice) {
    if (invoice->wHead == NULL) {
        return;
    }
    struct Ware *tmp = invoice->wHead;

    while (tmp) {
        invoice->netSum += tmp->netValue;
        invoice->taxSum += tmp->taxValue;
        invoice->grossSum += tmp->grossValue;

        tmp = tmp->wNext;
    }
}
