#ifndef INVOICE_INVOICE_H
#define INVOICE_INVOICE_H

struct Invoice {
    char documentNumber[10];
    char date[20];
    float netSum;
    float taxSum;
    float grossSum;
    struct Person *solder;
    struct Person *buyer;
    struct Ware *wHead;
};



struct Invoice
createInvoice(char documentNumber[10], char date[20], float netSum, float taxSum, float grossSum, struct Person *solder, struct Person *buyer);

void showInvoice(struct Invoice *invoice);

void addWare(struct Invoice *invoice, struct Ware *ware);

#endif //INVOICE_INVOICE_H
