#ifndef INVOICE_INPUT_H
#define INVOICE_INPUT_H

void readDataFromFile(struct Invoice **invoiceList, const char *PATH, char *fileName);

void readLine(char *target, int length);

int readInteger();

float readNumber();

float readPercentage();

char *readDate();

int readSelectOption(int start, int end);

int readYesOrNoOption(char text[]);

#endif //INVOICE_INPUT_H
