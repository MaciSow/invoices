#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Address.h"
#include "Person.h"
#include "utilities.h"

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
    strcpy(person->companyName, cutString(companyName,50));
    strcpy(person->name, cutString(name,50));
    strcpy(person->surname, cutString(surname,50));
    strcpy(person->nip, cutString(nip,11));
    strcpy(person->accountNumber, cutString(accountNumber,27));
    person->address = address;
}

void showPerson(struct Person *person) {
    if (!strcmp(person->nip, "---")) {
        printf("    %s %s",
               person->name,
               person->surname
        );
    } else {
        printf("    %s\t%s\n    %s %s",
               person->companyName,
               person->nip,
               person->name,
               person->surname
        );
    }

    printf("\n\n    Address:\n");
    showAddress(person->address);
};

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

