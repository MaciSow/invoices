#ifndef INVOICE_UTILITIES_H
#define INVOICE_UTILITIES_H

#include "Invoice.h"

void readData(struct Invoice **invoiceList);

void addInvoice(struct Invoice **invoiceList, struct Invoice *invoice);

void showInvoiceList(struct Invoice *invoiceList);

char *cutString(const char *string, int length);

int checkString(const char *string, char *value);

char *getCurrentDate(char dateFormat[]);

char *getFutureDate(char dateFormat[],int weeks);

float repeatUntilValid();

char *readLine(int length);

#endif //INVOICE_UTILITIES_H
