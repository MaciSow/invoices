#ifndef INVOICE_INVOICE_H
#define INVOICE_INVOICE_H

struct Invoice {
    char documentNumber[20];
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

struct Invoice *createInvoice();

void fillInvoice(struct Invoice *invoice, struct Person *solder, struct Person *buyer, char documentNumber[],
                 char date[], char paymentDeadline[], char netSum[], char taxSum[], char grossSum[], char paid[]);

void showInvoice(struct Invoice *invoice);

void addWare(struct Invoice *invoice, struct Ware *ware);

char *formatAccountNumber(const char *accountNumber);

void getDataInvoice(struct Invoice *invoice);

int isNegative(char string[]);

void issuingInvoice();

void putWareList(struct Invoice *invoice);

void calculateSumWares(struct Invoice *invoice);

void issuingInvoice(struct Invoice **invoiceList);

#endif //INVOICE_INVOICE_H
