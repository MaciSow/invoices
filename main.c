#include <stdio.h>
#include <string.h>
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

    showInvoice(invoiceList);



//    printf("%s %s %s %s",  "a:", "b", "c:", "d");

   // while (searchInvoicesByPaid(invoiceList));

//    printf("%d", strcmp("11.07.2020","11.07.2020"));
    // printf("%s", generateUniqueID(invoiceList));
//    issuingInvoice(&invoiceList);

// funkcja
//    showShortInvoiceList(invoiceList);
//    struct Invoice *selectedInvoice = selectInvoice(invoiceList);
//    showInvoice(selectedInvoice);
//    invoiceOptions(invoiceList, selectedInvoice);

//    selectedInvoice = selectInvoice(invoiceList);
//    showInvoice(selectedInvoice);
//    invoiceOptions(invoiceList, selectedInvoice);
///  end funkcja

    return 0;
}

// todo * zapętlanie edycji
// todo * menu użytkownika
// todo * zapis do pliku
// todo * sprzątanie
// todo * doxygen