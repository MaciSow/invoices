#include <stdio.h>

#include "structures/Person.h"
#include "structures/Ware.h"
#include "structures/Invoice.h"
#include "structures/Address.h"
#include "structures/Input.h"
#include "structures/InvoiceBox.h"

int main() {

    struct Invoice *invoiceList;
    invoiceList = NULL;

    readData(&invoiceList);
//    issuingInvoice(&invoiceList);

// funkcja
    showShortInvoiceList(invoiceList);
    struct Invoice *selectedInvoice = selectInvoice(invoiceList);
    showInvoice(selectedInvoice);
    invoiceOptions(invoiceList, selectedInvoice);
//
    showShortInvoiceList(invoiceList);
    selectedInvoice = selectInvoice(invoiceList);
    showInvoice(selectedInvoice);
    invoiceOptions(invoiceList, selectedInvoice);
//    end funkcja
    return 0;
}

// todo * anulowanie faktury
// todo * korekta faktury
// todo * wyszukanie faktury (po dacie)
// todo * unikalne ID dla faktury
// todo * wyswietlenie faktur do opłacenia (dane sprzedawcy i kupujacego nr konta i kwota...)
// todo * wyglad faktury
// todo * menu użytkownika
// todo * zapis do pliku
// todo * sprzątanie
// todo * doxygen