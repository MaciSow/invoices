#include <stdio.h>
#include <string.h>
#include "Ware.h"

struct Ware
createWare(char name[70], int amount, float netPrice, float netValue, float tax, float taxValue, float grossValue) {
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

//createWare2(char name[70], int amount, float netPrice, float netValue, float tax, float taxValue, float grossValue) {
//    struct Ware ware;
//
//    strcpy(ware.name, name);
//    ware.amount = amount;
//    ware.netPrice = netPrice;
//    ware.netValue = netValue;
//    ware.tax = tax;
//    ware.taxValue = taxValue;
//    ware.grossValue = grossValue;
//
//    ware.wNext = NULL;
//
//    return ware;
//}

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