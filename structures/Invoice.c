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

struct Invoice *createInvoice() {
    struct Invoice *invoice;
    invoice = (struct Invoice *) malloc(sizeof(struct Invoice));
    char *currentDate = getCurrentDate("%d.%m.%Y");

    strcpy(invoice->documentNumber, "");
    strcpy(invoice->date, currentDate);
    strcpy(invoice->paymentDeadline, "");
    invoice->netSum = 0;
    invoice->taxSum = 0;
    invoice->grossSum = 0;
    invoice->paid = 0;
    invoice->wHead = NULL;

    free(currentDate);
    return invoice;
}

void
fillInvoice(struct Invoice *invoice, struct Person *solder, struct Person *buyer, char documentNumber[], char date[]) {
    cutString(documentNumber, 20);
    cutString(date, 20);

    strcpy(invoice->documentNumber, documentNumber);
    strcpy(invoice->date, date);

    invoice->solder = solder;
    invoice->buyer = buyer;
}

void showInvoice(struct Invoice *invoice) {
    char *formattedAccountNumber = formatAccountNumber(invoice->solder->accountNumber);

    printf("\n");
    printSeparator(100, '=');

    printf("Invoice nr: %-72sDate: %s", invoice->documentNumber, invoice->date);

    showPersonsTogether(invoice->solder, invoice->buyer);

    printf("\n\n");
    printSeparator(100, '-');

    printf("%5s|%14s%10s%10s|%11s|%11s|%11s|%11s|%11s\n", "No.", "Name", "|", "Amount", "Net Price", "Net Val", "Tax",
           "Tax Val", "Gross Val");

    printSeparator(100, '-');

    if (invoice->wHead == NULL) {
        printf("List is empty");
    } else {
        int i = 1;
        struct Ware *tmp = invoice->wHead;
        do {
            showWare(tmp, i++);
            tmp = tmp->wNext;
        } while (tmp != NULL);
    }

    printf("\n%100s\n", "---------------------------------------");
    printf("%65s%11s|%11s|%11s\n", "Sum:", "Net", "Tax", "Gross");
    printf("%100s\n", "---------------------------------------");

    printf("%76.2f %11.2f %11.2f\n%17s %s\n%17s %s\n%17s %.2f",
           invoice->netSum,
           invoice->taxSum,
           invoice->grossSum,

           "Account Number:",
           formattedAccountNumber,
           "Payment Deadline:",
           invoice->paymentDeadline,
           "Paid:",
           invoice->paid
    );
    printf("\n");
    printSeparator(100, '=');

    free(formattedAccountNumber);
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

int readDataInvoice(struct Invoice *invoice) {
    int amountWeeks;
    int isPaid = 0;

    if (readYesOrNoOption("Is paid?")) {
        amountWeeks = 0;
        isPaid = 1;
    } else {
        printf("Payment deadline:\n [1] one week\n [2] two weeks\n [3] four weeks\nYour choice:");

        amountWeeks = readSelectOption(1, 3);
        amountWeeks = amountWeeks == 3 ? 4 : amountWeeks;
    }

    char *futureDate = getFutureDate("%d.%m.%Y", amountWeeks);
    strcpy(invoice->paymentDeadline, futureDate);
    free(futureDate);

    return isPaid;
}

void issuingInvoice(struct Invoice **invoiceList) {
    struct Invoice *invoice = createInvoice();
    struct Person *solder = createPerson();
    struct Person *buyer = createPerson();
    struct Address *addressSolder = createAddress();
    struct Address *addressBuyer = createAddress();

    char *id = generateUniqueID(*invoiceList);
    strcpy(invoice->documentNumber, id);
    free(id);

    int isPaid = readDataInvoice(invoice);

    readDataPerson(solder, 1);
    readDataAddress(addressSolder);

    readDataPerson(buyer, 0);
    readDataAddress(addressBuyer);

    solder->address = addressSolder;
    invoice->solder = solder;

    buyer->address = addressBuyer;
    invoice->buyer = buyer;

    putWareList(invoice);
    calculateSumWares(invoice);
    invoice->paid = isPaid ? invoice->grossSum : 0;

    addInvoice(invoiceList, invoice);
}

void putWareList(struct Invoice *invoice) {
    int isEnd;

    do {
        printf("\nWare\n");
        isEnd = 0;

        struct Ware *ware = createWare();
        readDataWare(ware);
        calculateValuesWare(ware);
        addWare(invoice, ware);

        if (readYesOrNoOption("\nAdd another ware?")) {
            isEnd = 1;
        }

    } while (isEnd);
}

void calculateSumWares(struct Invoice *invoice) {
    invoice->netSum = 0;
    invoice->taxSum = 0;
    invoice->grossSum = 0;

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

void deleteInvoice(struct Invoice *invoice) {
    deletePerson(invoice->solder);
    deletePerson(invoice->buyer);

    while (invoice->wHead) {
        struct Ware *tmp = invoice->wHead->wNext;
        free(invoice->wHead);
        invoice->wHead = tmp;
    }
    free(invoice);
}

void editInvoice(struct Invoice *invoiceList, struct Invoice *invoice) {
    int isPaid = readDataInvoice(invoice);

    if (readYesOrNoOption("Do you want change to current date")) {
        char *currentDate = getCurrentDate("%d/%m/%Y");
        char *uniqueId = generateUniqueID(invoiceList);

        strcpy(invoice->date, currentDate);
        strcpy(invoice->documentNumber, uniqueId);

        free(currentDate);
        free(uniqueId);
    }
    invoice->paid = isPaid ? invoice->grossSum : 0;
}

void wareOptions(struct Invoice *invoice, struct Ware *ware) {
    printf("\nWhat next?\n"
           " [1] Edit\n"
           " [2] Delete\n"
           " [3] Back\n"
           "Your choice:");

    int select = readSelectOption(1, 3);

    switch (select) {
        case 1 :
            editWare(ware);
            break;
        case 2:
            deleteWareFromList(invoice, ware);
            break;
        default:
            break;
    }
}

void showWareList(struct Invoice *invoice) {
    if (invoice->wHead == NULL) {
        printf("List is empty");
    } else {
        int counter = 1;
        struct Ware *tmp = invoice->wHead;
        do {
            printf("[ %2i ] - %s\n", counter++, tmp->name);
            tmp = tmp->wNext;
        } while (tmp != NULL);
    }
}

struct Ware *selectWare(struct Invoice *invoice) {
    printf("Get item number:");

    int length = lengthWareList(invoice->wHead);
    int choose = readSelectOption(1, length);

    int counter = 1;
    struct Ware *tmp = invoice->wHead;

    while (counter != choose) {
        tmp = tmp->wNext;
        counter++;
    }
    return tmp;
}

int lengthWareList(struct Ware *ware) {
    if (ware == NULL) {
        return 0;
    }

    int counter = 0;
    struct Ware *tmp = ware;

    do {
        tmp = tmp->wNext;
        counter++;
    } while (tmp != NULL);

    return counter;
}

void deleteWareFromList(struct Invoice *invoice, struct Ware *ware) {

    if (ware->wNext == NULL && ware == invoice->wHead) {
        invoice->wHead = NULL;
        free(ware);
        return;
    }

    if (ware == invoice->wHead) {
        invoice->wHead = ware->wNext;
        free(ware);
        return;
    }

    struct Ware *tmp = invoice->wHead;

    if (ware->wNext == NULL) {

        while (tmp) {
            if (tmp->wNext == ware) {
                tmp->wNext = NULL;
                free(ware);
                return;
            }
            tmp = tmp->wNext;
        }
    }

    while (tmp) {
        if (tmp->wNext == ware) {
            tmp->wNext = ware->wNext;
            free(ware);
            return;
        }
        tmp = tmp->wNext;
    }
}

char *generateUniqueID(struct Invoice *invoiceList) {
    char *uniqueId = malloc(16);
    memset(uniqueId, '\0', 16);

    char *currentDate = getCurrentDate("%d/%m/%Y");
    strcpy(uniqueId, currentDate);
    free(currentDate);

    if (invoiceList == NULL) {
        strcat(uniqueId, "/0000");
        return uniqueId;
    }

    int id = 0;
    struct Invoice *tmp = invoiceList;

    do {
        char current[11];
        strncpy(current, tmp->documentNumber, 10);
        current[10] = '\0';

        if (checkString(uniqueId, current)) {
            int currentId;
            char currentIdString[5];

            strncpy(currentIdString, tmp->documentNumber + 11, 4);
            currentIdString[4] = '\0';

            currentId = strtol(currentIdString, NULL, 10);
            id = id <= currentId ? currentId + 1 : id;
        }
        tmp = tmp->iNext;
    } while (tmp != NULL);

    char idString[5];
    strcat(uniqueId, "/");
    sprintf(idString, "%04d", id);
    strcat(uniqueId, idString);

    return uniqueId;
}

void showInvoiceToPaid(struct Invoice *invoice) {
    printf("Transfer data:\n");
    printf("%28s: %s %s %s\n", "Beneficiary", invoice->solder->companyName, invoice->solder->name,
           invoice->solder->surname);
    printf("%28s: %s %s\n%29s %s %s\n", "Beneficiary address", invoice->solder->address->street,
           invoice->solder->address->homeNumber, "", invoice->solder->address->postalCode,
           invoice->solder->address->city);

    char *formattedAccountNumber = formatAccountNumber(invoice->solder->accountNumber);
    char *currentDate = getCurrentDate("%d.%m.%Y");

    printf("%28s: %s\n", "Beneficiary's account number", formattedAccountNumber);
    printf("%28s: %s\n", "Title", invoice->documentNumber);
    printf("%28s: %.2f\n", "Amount", (invoice->grossSum - invoice->paid));
    printf("%28s: %s\n", "Date", currentDate);

    printf("\nWhat next?\n"
           " [1] Paid\n"
           " [2] Back\n"
           "Your choice:");

    int select = readSelectOption(1, 3);

    if (select == 1) {
        printf("\nInvoice paid successfully\n");
        invoice->paid = invoice->grossSum;
    }

    free(formattedAccountNumber);
    free(currentDate);
}