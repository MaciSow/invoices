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

