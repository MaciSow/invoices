#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Address.h"
#include "Person.h"
#include "../functions/utilities.h"
#include "../functions/input.h"

struct Person *createPerson() {
    struct Person *person;
    person = (struct Person *) malloc(sizeof(struct Person));

    strcpy(person->companyName, "Osoba_prywatna");
    strcpy(person->nip, "---");
    strcpy(person->accountNumber, "---");
    person->address = NULL;

    return person;
}

void fillPerson(struct Person *person, struct Address *address, char companyName[], char name[], char surname[],
                char nip[], char accountNumber[]) {
    cutString(companyName, 50);
    cutString(name, 50);
    cutString(surname, 50);
    cutString(nip, 11);

    if (strcmp(accountNumber, "---") != 0) {
        cutString(accountNumber, 27);
        strcpy(person->accountNumber, accountNumber);
    }

    strcpy(person->companyName, companyName);
    strcpy(person->name, name);
    strcpy(person->surname, surname);
    strcpy(person->nip, nip);

    person->address = address;
}

void deletePerson(struct Person *person) {
    free(person->address);
    free(person);
}

void readDataPerson(struct Person *person, int isSolder) {
    int isCompany;

    if (isSolder) {
        printf("\nSolder\n");
    } else {
        printf("\nBuyer\n");
        isCompany = readYesOrNoOption("Do you have company?");
    }

    if (isSolder || isCompany) {
        printf("Company name:");
        readLine(person->companyName, 50);

        printf("NIP:");
        readLine(person->nip, 11);
    }

    printf("Name:");
    readLine(person->name, 50);

    printf("Surname:");
    readLine(person->surname, 50);

    if (isSolder) {
        printf("Account Number:");
        readLine(person->accountNumber, 27);
    }
}

void editPerson(struct Person *person, int isSolder) {
    readDataPerson(person, isSolder);
}

void showPersonsTogether(struct Person *solder, struct Person *buyer) {
    char *solderData = getLinePerson(solder);
    char *buyerData = getLinePerson(buyer);
    printf("\n\n%10s: %-40s%10s: %-40s", "Solder", solderData, "Buyer", buyerData);
    free(solderData);
    free(buyerData);

    solderData = concatenationStrings(solder->address->street, solder->address->homeNumber);
    buyerData = concatenationStrings(buyer->address->street, buyer->address->homeNumber);
    printf("\n%10s: %-40s%10s: %-40s", "Address", solderData, "Address", buyerData);
    free(solderData);
    free(buyerData);

    solderData = concatenationStrings(solder->address->postalCode, solder->address->city);
    buyerData = concatenationStrings(buyer->address->postalCode, buyer->address->city);
    printf("\n%11s %-40s%11s %-40s", " ", solderData, " ", buyerData);
    free(solderData);
    free(buyerData);

    printf("\n%10s: %-40s", "NIP", solder->nip);
    if (isCompany(buyer)) {
        printf("%10s: %-40s", "NIP", buyer->nip);
    }
}

void showPersonsInLine(struct Person *solder, struct Person *buyer) {
    char *nameWithSurname = concatenationStrings(solder->name, solder->surname);
    printf("%16s %-20s %-30s\n", "Solder:", solder->companyName, nameWithSurname);
    free(nameWithSurname);

    nameWithSurname = concatenationStrings(buyer->name, buyer->surname);
    printf("%16s %-20s %-30s", "Buyer:", isCompany(buyer) ? buyer->companyName : "", nameWithSurname);
    free(nameWithSurname);
}

char *getLinePerson(struct Person *person) {
    char *lineString = malloc(150);
    memset(lineString, '\0', 150);

    if (isCompany(person)) {
        strcpy(lineString, person->companyName);
        strcat(lineString, " ");
    }
    strcat(lineString, person->name);
    strcat(lineString, " ");
    strcat(lineString, person->surname);
    strcat(lineString, "\0");

    return lineString;
}

int isCompany(struct Person *person) {
    if (strcmp(person->nip, "---") != 0) {
        return 1;
    }
    return 0;
}
