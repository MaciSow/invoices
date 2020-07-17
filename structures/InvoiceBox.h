#ifndef INVOICE_INVOICEBOX_H
#define INVOICE_INVOICEBOX_H

void addInvoice(struct Invoice **invoiceList, struct Invoice *invoice);

void showInvoiceList(struct Invoice *invoiceList);

struct Invoice *selectInvoice(struct Invoice *invoiceList);

void deleteInvoiceFromList(struct Invoice **invoiceList, struct Invoice *invoice);

int lengthInvoiceList(struct Invoice *invoiceList);

void invoiceOptions(struct Invoice **invoiceList, struct Invoice *invoice);

void invoiceEditOptions(struct Invoice *invoiceList, struct Invoice *invoice);

void searchInvoicesByDate(struct Invoice **invoiceList, char date[]);

int searchInvoicesByPaid(struct Invoice **invoiceList);

void deleteInvoiceList(struct Invoice **invoiceList);

#endif //INVOICE_INVOICEBOX_H
