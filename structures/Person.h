#ifndef INVOICE_PERSON_H
#define INVOICE_PERSON_H

struct Person {
    char companyName[50];
    char name[50];
    char surname[50];
    char nip[20];
    char accountNumber[30];
    struct Address *address;
};


struct Person createPerson(char companyName[50], char name[50], char surname[50], char nip[20], struct Address *address);

void fillPerson(struct Person *person, struct Address *address, char companyName[50], char name[50], char surname[50], char nip[20], char accountNumber[30]);

void showPerson(struct Person *person);

void deletePerson(struct Person *person);

#endif //INVOICE_PERSON_H
