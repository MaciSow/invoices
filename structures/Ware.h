#ifndef INVOICE_WARE_H
#define INVOICE_WARE_H

struct Ware {
    char name[150];
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

void fillWare(struct Ware *ware, char name[150], char amount[10], char netPrice[15], char netValue[15], char tax[10],
              char taxValue[15], char grossValue[15]);

void showWare(struct Ware *ware, int i);

#endif //INVOICE_WARE_H
