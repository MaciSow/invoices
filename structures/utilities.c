#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utilities.h"
#include "Invoice.h"
#include "Person.h"
#include "Address.h"
#include "Ware.h"

void readData() {
    char string[255];
    FILE *ptr;

    if ((ptr = fopen("C:\\Users\\macie\\Desktop\\invoice\\invoice.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    int length;
    int index = 0;
    int start = 0;
    char firstSectionData[18][50];
    char wareData[7][50];

    int section = 1;

    struct Invoice *invoice;
    while (fgets(string, 50, (FILE *) ptr) != NULL) {

        if (checkString(string, "------")) {

            struct Address *addressSolder;
            addressSolder = (struct Address *) malloc(sizeof(struct Address));
            fillAddress(addressSolder, firstSectionData[6], firstSectionData[7], firstSectionData[8],
                        firstSectionData[9]);

            struct Address *addressBuyer;
            addressBuyer = (struct Address *) malloc(sizeof(struct Address));
            fillAddress(addressBuyer, firstSectionData[14], firstSectionData[15],
                        firstSectionData[16], firstSectionData[17]);

            struct Person *solder;
            solder = (struct Person *) malloc(sizeof(struct Person));
            fillPerson(solder, addressSolder, firstSectionData[2], firstSectionData[4], firstSectionData[5],
                       firstSectionData[3]);

            struct Person *buyer;
            buyer = (struct Person *) malloc(sizeof(struct Person));
            fillPerson(buyer, addressBuyer, firstSectionData[10], firstSectionData[12], firstSectionData[13],
                       firstSectionData[11]);

            invoice = (struct Invoice *) malloc(sizeof(struct Invoice));
            printf("invoice: %p\n", invoice);
            fillInvoice(invoice, solder, buyer, firstSectionData[0], firstSectionData[1], "0", "0", "0");

            section = 2;
            continue;
        }

        if (checkString(string, "++++++")) {
            index = 0;
            section = 3;
            continue;
        }

        if (checkString(string, "######")) {
//            invoice.netSum = 15;
            index = 0;
            section = 1;
            continue;
        }

        switch (section) {
            case 1 :
                for (int i = 0; i < strlen(string); ++i) {

                    if (string[i] == ' ' || i == strlen(string) - 1) {
                        length = i - start;
                        memset(firstSectionData[index], 0, 50);
                        strncpy(firstSectionData[index++], string + start, length);
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

                break;
            default:
                break;
        }
        start = 0;
    }

    showInvoice(invoice);

    fclose(ptr);
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