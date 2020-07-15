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
    strcpy(person->companyName, cutString(companyName, 50));
    strcpy(person->name, cutString(name, 50));
    strcpy(person->surname, cutString(surname, 50));
    strcpy(person->nip, cutString(nip, 11));
    strcpy(person->accountNumber, cutString(accountNumber, 27));
    person->address = address;
}

void showPerson(struct Person *person) {
    if (isCompany(person)) {
        printf("    %s\t%s\n    %s %s",
               person->companyName,
               person->nip,
               person->name,
               person->surname
        );
    } else {
        printf("    %s %s",
               person->name,
               person->surname
        );
    }

    printf("\n\n    Address:\n");
    showAddress(person->address);
};

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
        printf("%10s: %-40s", "NIP", buyerData);
    }
}

void deletePerson(struct Person *person) {
    free(person->address);
    free(person);
}

void getDataPerson(struct Person *person, int isSolder) {
    char isCompany;

    if (isSolder) {
        printf("\nSolder\n");
    } else {
        printf("\nBuyer\nDo you have company? [Y/n]:");
        isCompany = (char) readLine(2)[0];
    }

    if (isSolder || isCompany == '\n' || isCompany == 'Y' || isCompany == 'y') {

        printf("Company name:");
        strcpy(person->companyName, readLine(50));

        printf("NIP:");
        strcpy(person->nip, readLine(11));
    }

    printf("Name:");
    strcpy(person->name, readLine(50));

    printf("Surname:");
    strcpy(person->surname, readLine(50));

    if (isSolder) {
        printf("Account Number:");
        strcpy(person->accountNumber, readLine(27));
    }
}

void editPerson(struct Person *person, int isSolder) {
    getDataPerson(person, isSolder);
}

void showPersonsInLine(struct Person *solder, struct Person *buyer) {
    char *nameWithSurname = concatenationStrings(solder->name, solder->surname);
    printf("         Solder: %-20s %-30s\n", solder->companyName, nameWithSurname);
    free(nameWithSurname);

    nameWithSurname = concatenationStrings(buyer->name, buyer->surname);
    printf("         Buyer:  %-20s %-30s", isCompany(buyer) ? buyer->companyName : "", nameWithSurname);
    free(nameWithSurname);
}

char *getLinePerson(struct Person *person) {
    char *string = malloc(150);
    memset(string, '\0', 150);

    if (isCompany(person)) {
        strcpy(string, person->companyName);
        strcat(string, " ");
    }
    strcat(string, person->name);
    strcat(string, " ");
    strcat(string, person->surname);
    strcat(string, "\0");

    return string;
}

int isCompany(struct Person *person) {
    if (strcmp(person->nip, "---") != 0) {
        return 1;
    }
    return 0;
}
