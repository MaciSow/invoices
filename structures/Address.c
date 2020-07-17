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
    cutString2(street, 50);
    cutString2(homeNumber, 10);
    cutString2(postalCode, 10);
    cutString2(city, 50);

    strcpy(address->street, street);
    strcpy(address->homeNumber, homeNumber);
    strcpy(address->postalCode, postalCode);
    strcpy(address->city, city);

//    strcpy(address->street, (street,50));
//    strcpy(address->homeNumber, cutString(homeNumber,10));
//    strcpy(address->postalCode, cutString(postalCode,10));
//    strcpy(address->city, cutString(city,50));
};

void showAddress(struct Address *address) {
    printf("      %s %s\n      %s\n      %s\n",
           address->street,
           address->homeNumber,
           address->postalCode,
           address->city);
};

void getDataAddress(struct Address *address) {
    printf("Street:");
    readLine2(address->street, 50);

    printf("Home number:");
    readLine2(address->homeNumber, 10);

    printf("Postal code:");
    readLine2(address->postalCode, 7);

    printf("City:");
    readLine2(address->city, 50);
}

void editAddress(struct Address *address) {
    getDataAddress(address);
}