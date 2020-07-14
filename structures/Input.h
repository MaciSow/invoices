#ifndef INVOICE_INPUT_H
#define INVOICE_INPUT_H

void readData(struct Invoice **invoiceList);

char *readLine(int length);

float readNumber();

int readInteger();

int repeatUntilSelectValid(int start, int end);

float readPercentage();

char *getDate();

#endif //INVOICE_INPUT_H
