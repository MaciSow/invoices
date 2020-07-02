#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures/Person.h"
#include "structures/Ware.h"
#include "structures/Invoice.h"
#include "structures/Address.h"
#include "structures/utilities.h"

int main() {

    struct Invoice *invoiceList;
    invoiceList = NULL;

    readData(&invoiceList);

    showInvoiceList(invoiceList);

    return 0;
}

// todo * wystawienie faktury (funckje odczytujące dane z konsoli w osobnych strukturach)
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