#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Ware.h"

struct Ware
createWare(char name[150], int amount, float netPrice, float netValue, float tax, float taxValue, float grossValue) {
    struct Ware ware;

    strcpy(ware.name, name);
    ware.amount = amount;
    ware.netPrice = netPrice;
    ware.netValue = netValue;
    ware.tax = tax;
    ware.taxValue = taxValue;
    ware.grossValue = grossValue;

    ware.wNext = NULL;

    return ware;
}

void fillWare(struct Ware *ware, char name[150], char amount[10], char netPrice[15], char netValue[15], char tax[10],
              char taxValue[15], char grossValue[15]) {

    strcpy(ware->name, name);
    ware->amount = strtol(amount,NULL,10);
    ware->netPrice = strtof(netPrice,NULL);
    ware->netValue = strtof(netValue,NULL);
    ware->tax = strtof(tax,NULL);
    ware->taxValue = strtof(taxValue,NULL);
    ware->grossValue = strtof(grossValue,NULL);

    ware->wNext = NULL;
}

void showWare(struct Ware *ware) {
    printf("%s\n %i \n %.2f \n %.2f \n %.2f \n %.2f \n %.2f \n",
           ware->name,
           ware->amount,
           ware->netPrice,
           ware->netValue,
           ware->tax,
           ware->taxValue,
           ware->grossValue);
}