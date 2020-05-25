#ifndef INVOICE_STRUCTS_H
#define INVOICE_STRUCTS_H

struct Address {
    char street[50];
    char postalCode[10];
    char city[50];
};

struct Person {
    char companyName[50];
    char name[50];
    char surname[50];
    char nip[20];
    struct Address address;
};

struct Ware {
    char name[70];
    int amount;
    float netPrice;
    float netValue;
    float tax;
    float taxValue;
    float grossValue;
};

struct Invoice {
    char documentNumber[10];
    char date[20];
    float netSum;
    float taxSum;
    float grossSum;
    struct Person solder;
    struct Person buyer;
    struct Ware wares[10];
};
#endif //INVOICE_STRUCTS_H
