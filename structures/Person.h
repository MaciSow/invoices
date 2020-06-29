#ifndef INVOICE_PERSON_H
#define INVOICE_PERSON_H

struct Person {
    char companyName[50];
    char name[50];
    char surname[50];
    char nip[20];
    struct Address *address;
};

struct Person createPerson(char companyName[50], char name[50], char surname[50], char nip[20], struct Address *address);

void showPerson(struct Person *person);

#endif //INVOICE_PERSON_H
