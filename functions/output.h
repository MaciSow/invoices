#ifndef INVOICE_OUTPUT_H
#define INVOICE_OUTPUT_H

void saveDataToFile(struct Invoice **invoiceList, const char *PATH, char *fileName);

void printPersonData(struct Person *person, FILE *fptr);

void printAddress(struct Address *address, FILE *fptr);

void printWare(struct Ware *ware, FILE *fptr);

void printSeparator(int n, char separator);

void fprintSeparator(int n, char separator, FILE *fptr);

void printMenu();

#endif //INVOICE_OUTPUT_H
