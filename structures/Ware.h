#ifndef INVOICE_WARE_H
#define INVOICE_WARE_H

struct Ware {
    char name[70];
    int amount;
    float netPrice;
    float netValue;
    float tax;
    float taxValue;
    float grossValue;

    struct Ware *wNext;
};

struct Ware
createWare(char name[70], int amount, float netPrice, float netValue, float tax, float taxValue, float grossValue);

void showWare(struct Ware *ware);
#endif //INVOICE_WARE_H
