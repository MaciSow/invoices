#ifndef INVOICE_PERSON_H
#define INVOICE_PERSON_H

struct Person {
    char companyName[50];
    char name[50];
    char surname[50];
    char nip[11];
    char accountNumber[27];
    struct Address *address;
};

struct Person *createPerson();

void
fillPerson(struct Person *person, struct Address *address, char companyName[], char name[], char surname[], char nip[],
           char accountNumber[]);

void showPerson(struct Person *person);

void deletePerson(struct Person *person);

void getDataPerson(struct Person *person, int isSolder);

#endif //INVOICE_PERSON_H
