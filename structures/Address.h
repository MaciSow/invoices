#ifndef INVOICE_ADDRESS_H
#define INVOICE_ADDRESS_H

struct Address {
    char street[50];
    char homeNumber[10];
    char postalCode[10];
    char city[50];
};

struct Address createAddress(char street[50], char homeNumber[10], char postalCode[10], char city[50]);

void fillAddress(struct Address *address, char street[50], char homeNumber[10], char postalCode[10], char city[50]);

void showAddress(struct Address *address);



#endif //INVOICE_ADDRESS_H
