/** @file */

#ifndef INVOICE_WARE_H
#define INVOICE_WARE_H

/**
	Struktura towaru/usługi.
*/
struct Ware {
    char name[150];         ///< nazwa
    int amount;             ///< ilość
    float netPrice;         ///< cena netto
    float netValue;         ///< wartość netto
    float tax;              ///< stawka VAT
    float taxValue;         ///< VAT
    float grossValue;       ///< wartość brutto
    struct Ware *wNext;     ///< wskaźnik na następny element listy towarów/usług
};

/** Konstruktor alokuje pamięć na strukturę.
*@return wskaźnik na utworzoną strukturę towaru/usługi
*/
struct Ware *createWare();

/** Funkcja wypełnia strukturę towaru/usługi danymi.
*@param ware wskaźnik na towar/usługę
*@param name tablica znaków zawierająca nazwę
*@param amount tablica znaków zawierająca ilość
*@param netPrice tablica znaków zawierająca cenę netto
*@param tax tablica znaków zawierająca podatek
*/
void fillWare(struct Ware *ware, char name[], char amount[], char netPrice[], char tax[]);

/** Funkcja wyświetla towar/usługę.
*@param ware wskaźnik na towar/usługę
*@param i numer towaru usługi na liście
*/
void showWare(struct Ware *ware, int i);

/** Funkcja prosi o i odczytuje dane towaru/usługi z konsoli oraz przypisuje je do towaru/usługi.
*@param ware wskaźnik na towar/usługę do której będą przekazane dane
*/
void readDataWare(struct Ware *ware);

/** Funkcja prosi o i odczytuje nowe dane towaru/usługi do edycji z konsoli oraz przypisuje je do towaru/usługi.
*@param ware wskaźnik na towar/usługę do która będzie edytowana
*/
void editWare(struct Ware *ware);

/** Funkcja wyliczająca i przypisująca do towaru/usługi wartości netto brutto i VAT.
*@param ware wskaźnik na towar/usługę
*/
void calculateValuesWare (struct Ware *ware);

#endif //INVOICE_WARE_H
