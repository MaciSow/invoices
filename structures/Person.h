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

void deletePerson(struct Person *person);

void readDataPerson(struct Person *person, int isSolder);

void editPerson(struct Person *person, int isSolder);

void showPersonsTogether(struct Person *solder,struct Person *buyer );

void showPersonsInLine(struct Person *solder, struct Person *buyer);

char* getLinePerson(struct Person *person);

int isCompany(struct Person *person);

#endif //INVOICE_PERSON_H
