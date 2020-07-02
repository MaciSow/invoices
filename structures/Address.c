#include <stdio.h>
#include <string.h>
#include "Address.h"

struct Address createAddress(char street[50], char homeNumber[10], char postalCode[10], char city[50]) {
    struct Address address;

    strcpy(address.street, street);
    strcpy(address.homeNumber, homeNumber);
    strcpy(address.postalCode, postalCode);
    strcpy(address.city, city);

    return address;
};

void fillAddress(struct Address *address, char data[4][50]) {

    printf("passed: %p\n", address);

    strcpy(address->street, data[0]);
    strcpy(address->homeNumber, data[1]);
    strcpy(address->postalCode, data[2]);
    strcpy(address->city, data[3]);
};

void showAddress(struct Address *address) {
    printf("%s %s\n%s\n%s",
           address->street,
           address->homeNumber,
           address->postalCode,
           address->city);
};