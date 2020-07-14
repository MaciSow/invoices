#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Ware.h"
#include "utilities.h"
#include "Input.h"

struct Ware *createWare() {
    struct Ware *ware;
    ware = (struct Ware *) malloc(sizeof(struct Ware));

    ware->wNext = NULL;
    return ware;
}

void fillWare(struct Ware *ware, char name[], char amount[], char netPrice[], char tax[]) {
    strcpy(ware->name, cutString(name,150));
    ware->amount = strtol(amount, NULL, 10);
    ware->netPrice = strtof(netPrice, NULL);
    ware->tax = strtof(tax, NULL)/100;
    calculateValuesWare(ware);
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
    ware->amount = (int) readNumber();

    printf("Net Price:");
    ware->netPrice = readNumber();

    printf("Tax:");
    ware->tax = readPercentage();
}

void calculateValuesWare(struct Ware *ware) {
    ware->netValue = ware->netPrice*(float)ware->amount;
    ware->taxValue = ware->netValue * ware->tax;
    ware->grossValue = ware->netValue + ware->taxValue;
}

void editWare(struct Ware *ware){
    getDataWare(ware);
    calculateValuesWare(ware);
}
