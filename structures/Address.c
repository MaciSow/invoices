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
    strcpy(address->street, cutString(street,50));
    strcpy(address->homeNumber, cutString(homeNumber,10));
    strcpy(address->postalCode, cutString(postalCode,10));
    strcpy(address->city, cutString(city,50));
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
    strcpy(address->street, readLine(50));

    printf("Home number:");
    strcpy(address->homeNumber, readLine(10));

    printf("Postal code:");
    strcpy(address->postalCode, readLine(7));

    printf("City:");
    strcpy(address->city, readLine(50));
}

void editAddress(struct Address *address){
    getDataAddress(address);
}