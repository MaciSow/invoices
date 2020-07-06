#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Ware.h"
#include "utilities.h"

struct Ware *createWare() {
    struct Ware *ware;
    ware = (struct Ware *) malloc(sizeof(struct Ware));

    return ware;
}

void fillWare(struct Ware *ware, char name[], char amount[], char netPrice[], char netValue[], char tax[],
              char taxValue[], char grossValue[]) {

    strcpy(ware->name, cutString(name,150));
    ware->amount = strtol(amount, NULL, 10);
    ware->netPrice = strtof(netPrice, NULL);
    ware->netValue = strtof(netValue, NULL);
    ware->tax = strtof(tax, NULL)/100;
    ware->taxValue = strtof(taxValue, NULL);
    ware->grossValue = strtof(grossValue, NULL);

    ware->wNext = NULL;
}

void showWare(struct Ware *ware, int i) {
    printf("%4i. %-22s %11i %11.2f %11.2f %10.0f%% %11.2f %11.2f\n",
           i,
           ware->name,
           ware->amount,
           ware->netPrice,
           ware->netValue,
           ware->tax*100,
           ware->taxValue,
           ware->grossValue);
}

void getDataWare(struct Ware *ware) {
    printf("Name:");
    strcpy(ware->name, readLine(150));

    printf("Amount:");
    ware->amount = (int) repeatUntilValid();

    printf("Net Price:");
    ware->netPrice = repeatUntilValid();

    printf("Tax:");
    ware->tax = repeatUntilValid() / 100;
}

void calculateValuesWare(struct Ware *ware) {
    ware->netValue = ware->netPrice;
    ware->taxValue = ware->netPrice * ware->tax;
    ware->grossValue = ware->netValue + ware->taxValue;
}

