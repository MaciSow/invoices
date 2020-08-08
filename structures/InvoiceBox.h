#ifndef INVOICE_INVOICEBOX_H
#define INVOICE_INVOICEBOX_H

/** Funkcja dodająca funkcję do jednokierunkowej listy funkcji.
*@param invoiceList wskaźnik na wskaźnik na głowę listy faktur
*@param invoice wskaźnik na fakturę która ma być dodana
*@return
*/
void addInvoice(struct Invoice **invoiceList, struct Invoice *invoice);

/** Funkcja wyświetla listę faktur.
*@param invoiceList wskaźnik na głowę listy faktur
*/
void showInvoiceList(struct Invoice *invoiceList);

/** Funkcja prosi o numer faktury na podstawie wcześniej wyświetlonej listy.
*@param invoiceList wskaźnik na głowę listy faktur
*@return wskaźnik na wybraną fakturę
*/
struct Invoice *selectInvoice(struct Invoice *invoiceList);

/** Funkcja usuwa fakturę z listy faktur.
*@param invoiceList wskaźnik na wskaźnik na głowę listy faktur
*@param invoice wskaźnik na fakturę do usunięcia
*/
void deleteInvoiceFromList(struct Invoice **invoiceList, struct Invoice *invoice);

/** Funkcja oblicza długość listy faktur.
*@param invoiceList wskaźnik na głowę listy faktur
*@return długość listy
*/
int lengthInvoiceList(struct Invoice *invoiceList);

/** Funkcja wyświetla i prosi o wybór opcji akcji dla faktury.
*@param invoiceList wskaźnik na wskaźnik na głowę listy faktur
*@param invoice wskaźnik na wybraną fakturę
*/
void invoiceOptions(struct Invoice **invoiceList, struct Invoice *invoice);

/** Funkcja wyświetla i prosi o wybór opcji edycji dla faktury.
*@param invoiceList wskaźnik na głowę listy faktur
*@param invoice wskaźnik na wybraną fakturę
*/
void invoiceEditOptions(struct Invoice *invoiceList, struct Invoice *invoice);

/** Funkcja wyszukuje i wyświetla faktury na podstawie daty.
*@param invoiceList wskaźnik na wskaźnik na głowę listy faktur
*@param date data przekazana jako tablica znaków
*/
void searchInvoicesByDate(struct Invoice **invoiceList, char date[]);

/** Funkcja wyszukuje i wyświetla faktury które nie są opłacone.
*@param invoiceList wskaźnik na wskaźnik na głowę listy faktur
*/
int searchInvoicesByPaid(struct Invoice **invoiceList);

/** Funkcja usuwa listę faktur i zwalnia pamięć.
*@param invoiceList wskaźnik na wskaźnik na głowę listy faktur
*/
void deleteInvoiceList(struct Invoice **invoiceList);

#endif //INVOICE_INVOICEBOX_H
