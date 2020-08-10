/** @file */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Address.h"
#include "../functions/utilities.h"
#include "../functions/input.h"

struct Address *createAddress() {
    struct Address *address;
    address = (struct Address *) malloc(sizeof(struct Address));

    return address;
}

void fillAddress(struct Address *address, char street[], char homeNumber[], char postalCode[], char city[]) {
    cutString(street, 50);
    cutString(homeNumber, 10);
    cutString(postalCode, 10);
    cutString(city, 50);

    strcpy(address->street, street);
    strcpy(address->homeNumber, homeNumber);
    strcpy(address->postalCode, postalCode);
    strcpy(address->city, city);
}

void readDataAddress(struct Address *address) {
    printf("Street:");
    readLine(address->street, 50);

    printf("Home number:");
    readLine(address->homeNumber, 10);

    printf("Postal code:");
    readLine(address->postalCode, 7);

    printf("City:");
    readLine(address->city, 50);
}

void editAddress(struct Address *address) {
    readDataAddress(address);
}