#ifndef INVOICE_INPUT_H
#define INVOICE_INPUT_H

void readDataFromFile(struct Invoice **invoiceList,const char *PATH, char *fileName);

char *readLine(int length);

void readLine2(char *target, int length);

int readInteger();

float readNumber();

float readPercentage();

char *readDate();

int readSelectOption(int start, int end);

#endif //INVOICE_INPUT_H
