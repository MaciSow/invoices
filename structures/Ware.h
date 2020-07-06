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

struct Ware *createWare();

void fillWare(struct Ware *ware, char name[], char amount[], char netPrice[], char tax[]);

void showWare(struct Ware *ware, int i);

void getDataWare(struct Ware *ware);

void calculateValuesWare (struct Ware *ware);

#endif //INVOICE_WARE_H
