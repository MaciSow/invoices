#ifndef INVOICE_INPUT_H
#define INVOICE_INPUT_H

void readData(struct Invoice **invoiceList);

char *readLine(int length);

float repeatUntilValid();

int readInteger();

int repeatUntilSelectValid(int start, int end);

#endif //INVOICE_INPUT_H
