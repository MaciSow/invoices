#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Address.h"
#include "Person.h"

struct Person
createPerson(char companyName[50], char name[50], char surname[50], char nip[20], struct Address *address) {
    struct Person person;

    strcpy(person.companyName, companyName);
    strcpy(person.name, name);
    strcpy(person.surname, surname);
    strcpy(person.nip, nip);
    person.address = address;
    return person;

};

void fillPerson(struct Person *person, struct Address *address, char companyName[50], char name[50], char surname[50],
                char nip[20], char accountNumber[30]) {
    strcpy(person->companyName, companyName);
    strcpy(person->name, name);
    strcpy(person->surname, surname);
    strcpy(person->nip, nip);
    strcpy(person->accountNumber, accountNumber);
    person->address = address;
}

void showPerson(struct Person *person) {
    if (strcmp(person->nip, "---") == 0) {
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

