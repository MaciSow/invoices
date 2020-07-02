#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utilities.h"
#include "Invoice.h"
#include "Person.h"
#include "Address.h"
#include "Ware.h"

void readData(struct Invoice **invoiceList) {
    char string[255];
    FILE *ptr;

    if ((ptr = fopen("C:\\Users\\macie\\Desktop\\invoice\\invoice.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    int length;
    int counter = 0;
    int index = 0;
    int start = 0;
    char invoiceData[19][50];
    char wareData[7][50];
    char summaryData[5][15];
    int section = 1;
    struct Invoice *invoice;

    while (fgets(string, 50, (FILE *) ptr) != NULL) {

        if (checkString(string, "------")) {

            struct Address *addressSolder;
            addressSolder = (struct Address *) malloc(sizeof(struct Address));
            fillAddress(addressSolder, invoiceData[7], invoiceData[8], invoiceData[9],
                        invoiceData[10]);

            struct Address *addressBuyer;
            addressBuyer = (struct Address *) malloc(sizeof(struct Address));
            fillAddress(addressBuyer, invoiceData[15], invoiceData[16],
                        invoiceData[17], invoiceData[18]);

            struct Person *solder;
            solder = (struct Person *) malloc(sizeof(struct Person));
            fillPerson(solder, addressSolder, invoiceData[2], invoiceData[4], invoiceData[5],
                       invoiceData[3],invoiceData[6]);

            struct Person *buyer;
            buyer = (struct Person *) malloc(sizeof(struct Person));
            fillPerson(buyer, addressBuyer, invoiceData[11], invoiceData[13], invoiceData[14],
                       invoiceData[12],"");

            invoice = (struct Invoice *) malloc(sizeof(struct Invoice));
            fillInvoice(invoice, solder, buyer, invoiceData[0], invoiceData[1], "0", "0", "0","","0");

            section = 2;
            continue;
        }

        if (checkString(string, "++++++")) {
            index = 0;
            section = 3;
            continue;
        }

        if (checkString(string, "######")) {
            invoice->netSum = strtof(summaryData[0],NULL);
            invoice->taxSum = strtof(summaryData[1],NULL);
            invoice->grossSum = strtof(summaryData[2],NULL);
            strcpy(invoice->paymentDeadline,summaryData[3]);
            invoice->paid = strtof(summaryData[4],NULL);

            addInvoice(invoiceList,invoice);
            counter++;
            index = 0;
            section = 1;
            continue;
        }

        switch (section) {
            case 1 :
                for (int i = 0; i < strlen(string); ++i) {

                    if (string[i] == ' ' || i == strlen(string) - 1) {
                        length = i - start;
                        memset(invoiceData[index], 0, 50);
                        strncpy(invoiceData[index++], string + start, length);
                        start = ++i;
                    }
                }
                break;

            case 2 :
                index = 0;
                memset(wareData[index], 0, 50);
                strncpy(wareData[index++], string, strlen(string) - 1);

                fgets(string, 50, (FILE *) ptr);

                for (int i = 0; i < strlen(string); ++i) {
                    if (string[i] == ' ' || i == strlen(string) - 1) {
                        length = i - start;
                        memset(wareData[index], 0, 50);
                        strncpy(wareData[index++], string + start, length);
                        start = ++i;
                    }
                }

                struct Ware *ware;
                ware = (struct Ware *) malloc(sizeof(struct Ware));
                fillWare(ware, wareData[0], wareData[1], wareData[2], wareData[3], wareData[4], wareData[5],
                         wareData[6]);
                addWare(invoice, ware);

                break;

            case 3 :
                for (int i = 0; i < strlen(string); ++i) {

                    if (string[i] == ' ' || i == strlen(string) - 1) {
                        length = i - start;
                        memset(summaryData[index], 0, 50);
                        strncpy(summaryData[index++], string + start, length);
                        start = ++i;
                    }
                }
                break;
            default:
                break;
        }
        start = 0;
    }
    fclose(ptr);
    printf("\n\nFile read done\n%i invoices loaded\n", counter);
}

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

int checkString(const char *string, char *value) {
    if (!strlen(value)) {
        return 0;
    }

    for (int i = 0; i < strlen(value); i++) {
        if (string[i] != value[i]) {
            return 0;
        }
    }
    return 1;
};