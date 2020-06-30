#ifndef INVOICE_UTILITIES_H
#define INVOICE_UTILITIES_H
#include "Invoice.h"

void readData();

void addInvoice(struct Invoice **invoiceList, struct Invoice *invoice);

void showInvoiceList(struct Invoice *invoiceList);

#endif //INVOICE_UTILITIES_H
