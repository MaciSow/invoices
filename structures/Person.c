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
                char nip[20]) {
    strcpy(person->companyName, companyName);
    strcpy(person->name, name);
    strcpy(person->surname, surname);
    strcpy(person->nip, nip);
//    person->address = (struct Address *) malloc(sizeof(struct Address));
    person->address = address;
}

void showPerson(struct Person *person) {
    if (strcmp(person->nip, "---") == 0) {
        printf("%s\n%s %s",
               person->companyName,
               person->name,
               person->surname
        );
    } else {
        printf("%s\n%s %s\n%s",
               person->companyName,
               person->name,
               person->surname,
               person->nip
        );
    }

    printf("\n\nAdres:\n");
    showAddress(person->address);
};

void deletePerson(struct Person *person) {
    free(person->address);
    free(person);
}

