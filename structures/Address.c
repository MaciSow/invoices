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

void fillAddress(struct Address *address, char street[50], char homeNumber[10], char postalCode[10], char city[50]) {
    strcpy(address->street, street);
    strcpy(address->homeNumber, homeNumber);
    strcpy(address->postalCode, postalCode);
    strcpy(address->city, city);
};

void showAddress(struct Address *address) {
    printf("%s %s\n%s\n%s\n",
           address->street,
           address->homeNumber,
           address->postalCode,
           address->city);
};