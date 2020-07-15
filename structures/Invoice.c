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

    strcpy(invoice->documentNumber, "");
    strcpy(invoice->date, getCurrentDate("%d.%m.%Y"));
    invoice->netSum = 0;
    invoice->taxSum = 0;
    invoice->grossSum = 0;
    invoice->wHead = NULL;

    return invoice;
}

void fillInvoice(struct Invoice *invoice, struct Person *solder, struct Person *buyer, char documentNumber[],
                 char date[], char paymentDeadline[], char paid[]) {
    strcpy(invoice->documentNumber, cutString(documentNumber, 20));
    strcpy(invoice->date, cutString(date, 20));
    strcpy(invoice->paymentDeadline, cutString(paymentDeadline, 20));
    invoice->paid = strtof(paid, NULL);
    invoice->solder = solder;
    invoice->buyer = buyer;
};

void showInvoice(struct Invoice *invoice) {
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
           formatAccountNumber(invoice->solder->accountNumber),
           "Payment Deadline:",
           invoice->paymentDeadline,
           "Paid:",
           invoice->paid
    );
    printf("\n");
    printSeparator(100, '=');
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

        amountWeeks = readSelectOption(1, 3);
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

    strcpy(invoice->documentNumber, generateUniqueID(*invoiceList));
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
    invoice->paid = invoice->paid ? invoice->grossSum : 0;

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

void editInvoice(struct Invoice *invoice) {
    getDataInvoice(invoice);
    char choose;
    printf("Do you want change to current date[Y/n]:");
    choose = (char) readLine(2)[0];

    if (choose == '\n' || choose == 'Y' || choose == 'y') {
        strcpy(invoice->date, getCurrentDate("%d.%m.%Y"));
    }
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
    printf("Get item number: ");

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
    strcpy(uniqueId, getCurrentDate("%d/%m/%Y"));

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
            int currentId = 0;
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

    printf("%28s: %s\n", "Beneficiary's account number", formatAccountNumber(invoice->solder->accountNumber));
    printf("%28s: %s\n", "Title", invoice->documentNumber);
    printf("%28s: %.2f\n", "Amount", (invoice->grossSum - invoice->paid));
    printf("%28s: %s\n", "Date", getCurrentDate("%d.%m.%Y"));

    printf("\nWhat next?\n"
           " [1] Paid\n"
           " [2] Back\n"
           "Your choice:");

    int select = readSelectOption(1, 3);

    if (select == 1) {
        printf("\nInvoice paid successfully\n");
        invoice->paid = invoice->grossSum;
    }
}