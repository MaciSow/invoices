#ifndef INVOICE_INVOICE_H
#define INVOICE_INVOICE_H

/**
	Struktura faktury.
*/
struct Invoice {
    char documentNumber[20];      ///< unikalny numer faktury
    char date[20];                ///< data
    char paymentDeadline[20];     ///< termin płatności
    float netSum;                 ///< suma netto
    float taxSum;                 ///< suma vat
    float grossSum;               ///< suma brutto
    float paid;                   ///< zapłacona kwota
    struct Person *solder;        ///< wskaźnik na osobę sprzedawcy
    struct Person *buyer;         ///< wskaźnik na osobę nabywcy
    struct Ware *wHead;           ///< wskaźnik na głowę towarów/usług
    struct Invoice *iNext;        ///< wskaźnik na następny element listy faktur
};

/** Konstruktor wypełnia strukturę faktury domyślnymi danymi i alokuje pamięć na nią.
*@return wskaźnik na utworzoną strukturę faktury
*/
struct Invoice *createInvoice();

/** Funkcja wypełnia strukturę faktury danymi.
*@param invoice wskaźnik na fakturę do wypełnienia
*@param solder wskaźnik na sprzedawcę
*@param buyer wskaźnik na nabywcę
*@param documentNumber tablica znaków zawierająca numer faktury
*@param date tablica znaków zawierająca datę
*/
void fillInvoice(struct Invoice *invoice, struct Person *solder, struct Person *buyer, char documentNumber[],
                 char date[]);

/** Funkcja wyświetla fakturę w konsoli.
*@param wskaźnik na fakturę do wyświetlenia
*/
void showInvoice(struct Invoice *invoice);

/** Funkcja dodaje do faktury nowy towar/usługę.
*@param invoice wskaźnik na fakturę
*@param ware wskaźnik na towar/usługę która ma być dodana
*/
void addWare(struct Invoice *invoice, struct Ware *ware);

/** Funkcja prosi o i odczytuje dane faktury z konsoli oraz przypisuje je do faktury.
*@param invoice wskaźnik na fakturę do której będą przekazane dane
*@return 1 gdy faktura jest opłacona 0 w przeciwnym wypadku
*/
int readDataInvoice(struct Invoice *invoice);

/** Funkcja prosi o i odczytuje dane do wystawienia nowej faktury.
*@param invoiceList wskaźnik na wskaźnik na głowę listy faktur
*/
void issuingInvoice(struct Invoice **invoiceList);

/** Funkcja tworzy listę towarów/usług podczas wystawiania faktury.
*@param invoice wskaźnik na fakture
*/
void putWareList(struct Invoice *invoice);

/** Funkcja oblicza sumy wartości netto brutto i VAT na podstawie listy towarów/usług, i przypisuję je do faktury.
*@param invoice wskaźnik na fakturę
*/
void calculateSumWares(struct Invoice *invoice);

/** Funkcja usuwa fakturę i zwalnia pamięć.
*@param invoice wskaźnik na fakturę do usunięcia
*/
void deleteInvoice(struct Invoice *invoice);

/** Funkcja prosi o i odczytuje dane do edycji faktury.
*@param invoiceList wskaźnik na głowę listy faktur
*@param invoice wskaźnik na fakturę do edycji
*/
void editInvoice(struct Invoice *invoiceList, struct Invoice *invoice);

/** Funkcja wyświetla i prosi o wybór opcji akcji dla towaru/usługi.
*@param invoice wskaźnik na fakturę
*@param ware wskaźnik na wybrany towar/usługę
*/
void wareOptions(struct Invoice *invoice, struct Ware *ware);

/** Funkcja wyświetla listę towarów/usług.
*@param invoice wskaźnik do faktury w której jest lista towarów/usług do wyświetlenia
*/
void showWareList(struct Invoice *invoice);

/** Funkcja prosi o numer towaru/usługi na podstawie wcześniej wyświetlonej listy.
*@param invoice wskaźnik do faktury w której jest lista towarów/usług
*@return wskaźnik na wybraną towar/usługę
*/
struct Ware *selectWare(struct Invoice *invoice);

/** Funkcja oblicza długość listy towarów/usług.
*@param ware wskaźnik na głowę listy towarów/usług
*@return długość listy
*/
int lengthWareList(struct Ware *ware);

/** Funkcja usuwa towar/usługę z listy towarów/usług.
*@param invoice wskaźnik do faktury w której jest lista towarów/usług
*@param ware wskaźnik na towar/usługę do usunięcia
*/
void deleteWareFromList(struct Invoice *invoice, struct Ware *ware);

/** Funkcja generuje unikalny numer dokumentu na podstawie aktualnej daty i listy faktur.
*@param invoiceList wskaźnik na głowę listy faktur
*/
char *generateUniqueID(struct Invoice *invoiceList);

/** Funkcja wyświetla dane do przelewu i prosi o potwierdzenie.
*@param invoice wskaźnik na fakturę, która jest do opłacenia
*/
void showInvoiceToPaid(struct Invoice *invoice);

#endif //INVOICE_INVOICE_H
