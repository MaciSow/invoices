#ifndef INVOICE_ADDRESS_H
#define INVOICE_ADDRESS_H

struct Address {
    char street[50];
    char homeNumber[10];
    char postalCode[7];
    char city[50];
};

struct Address *createAddress();

void fillAddress(struct Address *address, char street[], char homeNumber[], char postalCode[], char city[]);

void showAddress(struct Address *address);

void getDataAddress(struct Address *address);

void editAddress(struct Address *address);

#endif //INVOICE_ADDRESS_H
