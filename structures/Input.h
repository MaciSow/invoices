#ifndef INVOICE_INPUT_H
#define INVOICE_INPUT_H

void readData(struct Invoice **invoiceList);

char *readLine(int length);

float repeatUntilValid();

int readInteger();

int repeatUntilSelectValid(int start, int end);

char *getDate();

int isValidDateFormat(const char *date);

int isValidDatePart(char *date, int start, int length, int min, int max);

#endif //INVOICE_INPUT_H
