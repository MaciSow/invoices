#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures/Address.h"
#include "../structures/Person.h"
#include "../structures/Ware.h"
#include "../structures/Invoice.h"
#include "../structures/InvoiceBox.h"
#include "input.h"
#include "utilities.h"

void readDataFromFile(struct Invoice **invoiceList) {
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
    char wareData[4][150];
    char summaryData[2][15];
    int section = 1;
    struct Invoice *invoice;

    while (fgets(string, 50, (FILE *) ptr) != NULL) {

        if (checkString(string, "------")) {

            struct Address *addressSolder = createAddress();
            fillAddress(addressSolder, invoiceData[7], invoiceData[8], invoiceData[9],
                        invoiceData[10]);

            struct Address *addressBuyer = createAddress();
            fillAddress(addressBuyer, invoiceData[15], invoiceData[16],
                        invoiceData[17], invoiceData[18]);

            struct Person *solder = createPerson();
            fillPerson(solder, addressSolder, invoiceData[2], invoiceData[4], invoiceData[5],
                       invoiceData[3], invoiceData[6]);

            struct Person *buyer = createPerson();
            fillPerson(buyer, addressBuyer, invoiceData[11], invoiceData[13], invoiceData[14],
                       invoiceData[12], "");

            invoice = createInvoice();
            fillInvoice(invoice, solder, buyer, invoiceData[0], invoiceData[1], "", "0");

            section = 2;
            continue;
        }

        if (checkString(string, "++++++")) {
            index = 0;
            section = 3;
            continue;
        }

        if (checkString(string, "######")) {
            calculateSumWares(invoice);
            strcpy(invoice->paymentDeadline, summaryData[0]);
            invoice->paid = strtof(summaryData[1], NULL);

            addInvoice(invoiceList, invoice);
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

                struct Ware *ware = createWare();

                fillWare(ware, wareData[0], wareData[1], wareData[2], wareData[3]);
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

char *readLine(int length) {
    char *str = malloc(length);
    memset(str, '\0', length);

    char letter;
    do {
        letter = (char) getchar();
    } while (letter == '\n');

    int i = 0;

    while (letter != '\n') {

        if (i < length - 1) {
            str[i] = letter;
        }

        i++;
        letter = (char) getchar();
    }

    str[length - 1] = '\0';
    return str;
}

int readInteger() {
    return strtol(readLine(15), NULL, 10);
}

float readNumber() {
    float value;
    int isInvalid;
    char string[15];

    do {
        isInvalid = 0;
        strcpy(string, readLine(15));

        if (isNegative(string)) {
            isInvalid = 1;
            printf("    - wrong data, try again:");
        }
    } while (isInvalid);

    value = strtof(string, NULL);
    return value;
}

float readPercentage() {
    float value;
    int isInvalid;
    char string[4];

    do {
        isInvalid = 0;
        strcpy(string, readLine(4));

        if (strtof(string, NULL) > 0 ? 0 : 1) {
            isInvalid = 1;
            printf("    - wrong data, try again:");
        }
    } while (isInvalid);

    value = strtof(string, NULL);
    return value / 100;
}

int readSelectOption(int start, int end) {
    int isInvalid;
    int select;

    do {
        isInvalid = 0;
        select = readInteger();
        if (!(select >= start && select <= end)) {
            isInvalid = 1;
            printf("    - wrong data, try again:");
        }
    } while (isInvalid);

    return select;
}

char *readDate() {
    char *string = malloc(11);
    memset(string, '\0', 11);
    printf("Get date (dd.mm.yyyy):");

    int isValid = 0;
    while (1) {
        strcpy(string, readLine(11));

        isValid = isValidDateFormat(string);
        isValid += isValidDatePart(string, 0, 2, 1, 31);
        isValid += isValidDatePart(string, 3, 2, 1, 12);
        isValid += isValidDatePart(string, 6, 4, 1970, 9999);

        if (isValid == 4) {
            return string;
        }

        printf("    - wrong data, try again:");
    }
}