#ifndef INVOICE_UTILITIES_H
#define INVOICE_UTILITIES_H

#include "Invoice.h"

void readData(struct Invoice **invoiceList);

void addInvoice(struct Invoice **invoiceList, struct Invoice *invoice);

void showInvoiceList(struct Invoice *invoiceList);

void readLine(char *string, char **words, int index);

int checkString(const char *string, char *value);
#endif //INVOICE_UTILITIES_H
