#ifndef INVOICE_OUTPUT_H
#define INVOICE_OUTPUT_H

void saveDataToFile(struct Invoice *invoiceList, const char *PATH, char *fileName);

void filePrintPersonData(struct Person *person, FILE *fptr);

void filePrintAddress(struct Address *address, FILE *fptr);

void filePrintWare(struct Ware *ware, FILE *fptr);

void filePrintSeparator(int n, char separator, FILE *fptr);

void printSeparator(int n, char separator);

void printMenu();

#endif //INVOICE_OUTPUT_H
