#include <stdio.h>
#include <string.h>
#include "Address.h"

struct Address createAddress(char street[50], char postalCode[10], char city[50]) {
    struct Address address;

    strcpy(address.street, street);
    strcpy(address.postalCode, postalCode);
    strcpy(address.city, city);

    return address;
};

void showAddress(struct Address *address) {
    printf("%s\n%s\n%s\n",
            address->street,
            address->postalCode,
            address->city);
};