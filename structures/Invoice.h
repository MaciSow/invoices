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
                 char date[], char paymentDeadline[], char paid[]);

void showInvoice(struct Invoice *invoice);

void addWare(struct Invoice *invoice, struct Ware *ware);

char *formatAccountNumber(const char *accountNumber);

void getDataInvoice(struct Invoice *invoice);

void putWareList(struct Invoice *invoice);

void calculateSumWares(struct Invoice *invoice);

void issuingInvoice(struct Invoice **invoiceList);

void deleteInvoice(struct Invoice *invoice);

void editInvoice(struct Invoice *invoice);

void wareOptions(struct Invoice *invoice, struct Ware *ware);

void showWareList(struct Invoice *invoice);

struct Ware *selectWare(struct Invoice *invoice);

int lengthWareList(struct Ware *ware);

void deleteWareFromList(struct Invoice *invoice, struct Ware *ware);

#endif //INVOICE_INVOICE_H
