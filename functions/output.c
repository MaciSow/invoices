#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures/Address.h"
#include "../structures/Person.h"
#include "../structures/Ware.h"
#include "../structures/Invoice.h"
#include "../structures/InvoiceBox.h"
#include "input.h"
#include "output.h"
#include "utilities.h"

void saveDataToFile(struct Invoice **invoiceList, const char *PATH, char *fileName) {
    FILE *fptr;

    char savePath[100] = {};
    strcpy(savePath, PATH);
    strcat(savePath, fileName);

    fptr = fopen(savePath, "w");

    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    if (*invoiceList == NULL) {
        return;
    }

    struct Invoice *tmp = *invoiceList;

    do {
        fprintf(fptr, "%s %s\n", tmp->documentNumber, tmp->date);
        printPersonData(tmp->solder, fptr);
        printPersonData(tmp->buyer, fptr);

        fprintSeparator(30, '-', fptr);

        struct Ware *tmpW = tmp->wHead;
        while (tmpW != NULL) {
            printWare(tmpW, fptr);
            tmpW = tmpW->wNext;
        }

        fprintSeparator(30, '+', fptr);

        fprintf(fptr, "%s %.2f\n", tmp->paymentDeadline, tmp->paid);

        fprintSeparator(40, '#', fptr);

        tmp = tmp->iNext;
    } while (tmp != NULL);

    fclose(fptr);
}

void printPersonData(struct Person *person, FILE *fptr) {
    fprintf(fptr, "%s %s\n%s %s\n",
            isCompany(person) ? person->companyName : "Osoba_prywatna",
            isCompany(person) ? person->nip : "---",
            person->name,
            person->surname
    );
    if (strcmp(person->accountNumber, "") != 0) {
        fprintf(fptr, "%s\n", person->accountNumber);
    }

    printAddress(person->address, fptr);
}

void printAddress(struct Address *address, FILE *fptr) {
    fprintf(fptr, "%s %s\n%s %s\n",
            address->street,
            address->homeNumber,
            address->postalCode,
            address->city
    );
}

void printWare(struct Ware *ware, FILE *fptr) {
    fprintf(fptr, "%s\n%d %.2f %.0f\n",
            ware->name,
            ware->amount,
            ware->netPrice,
            ware->tax * 100
    );
}

void printSeparator(int n, char separator) {
    char *dest = malloc(n + 1);
    memset(dest, separator, n);
    dest[n] = '\0';
    printf("%s\n", dest);
    free(dest);
}

void fprintSeparator(int n, char separator, FILE *fptr) {
    char *dest = malloc(n + 1);
    memset(dest, separator, n);
    dest[n] = '\0';
    fprintf(fptr, "%s\n", dest);
    free(dest);
}

void printMenu() {
    printSeparator(48, '=');
    printf("%26s\n", "MENU");
    printSeparator(48, '-');
    printf("[1] Show Invoices List\n");
    printf("[2] Issuing Invoice\n");
    printf("[3] Search Invoice By Date\n");
    printf("[4] Show Unpaid Invoices\n");
    printf("[5] Exit\n");
    printSeparator(48, '-');
    printf("Your choice:");
}