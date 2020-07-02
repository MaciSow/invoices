#ifndef INVOICE_INVOICE_H
#define INVOICE_INVOICE_H

struct Invoice {
    char documentNumber[10];
    char date[20];
    char paymentDeadline[20];
    float netSum;
    float taxSum;
    float grossSum;
    float paid;
    struct Person *solder;
    struct Person *buyer;
    struct Ware *wHead;
    struct Invoice *iNext;

};


struct Invoice
createInvoice(char documentNumber[10], char date[20], float netSum, float taxSum, float grossSum, struct Person *solder,
              struct Person *buyer);

struct Invoice createEmptyInvoice();

void fillInvoice(struct Invoice *invoice, struct Person *solder, struct Person *buyer, char documentNumber[10],
                 char date[20], char paymentDeadline[20], char netSum[15], char taxSum[15], char grossSum[15], char paid[15]);

void showInvoice(struct Invoice *invoice);

void addWare(struct Invoice *invoice, struct Ware *ware);

char *formatAccountNumber(const char *accountNumber);

#endif //INVOICE_INVOICE_H
