#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures/Person.h"
#include "structures/Ware.h"
#include "structures/Invoice.h"
#include "structures/Address.h"

int main() {
    struct Address address = createAddress("ul. Dolna 15", "24-444", "Bytom");
    struct Person person = createPerson("CarWash", "Jane", "Doe", "2151252", &address);

    struct Ware ware = createWare("schabowy", 14, 4, 4, 23, 4, 10);
    struct Ware wareee = createWare("kotlet", 22, 5, 4, 23, 4, 10);

    struct Invoice invoice = createInvoice("1215354", "26.07.2020", 234, 2131, 111, &person, &person);

    addWare(&invoice, &ware);
    addWare(&invoice, &wareee);

    showInvoice(&invoice);

    return 0;
}

