/** @file */

#ifndef INVOICE_ADDRESS_H
#define INVOICE_ADDRESS_H

/**
	Struktura adresu.
*/
struct Address {
    char street[50];         ///< nazwa ulicy
    char homeNumber[10];     ///< numer budynku
    char postalCode[7];      ///< kod pocztowy
    char city[50];           ///< nazwa miasta
};

/** Konstruktor alokuje pamięć na strukturę adresu.
*@return wskaźnik na utworzoną strukturę adresu
*/
struct Address *createAddress();

/** Funkcja wypełnia strukturę adresu danymi.
*@param address wskaźnik na adres to wypełnienia
*@param street tablica znaków zawierająca nazwę ulicy
*@param homeNumber tablica znaków zawierająca numer budynku
*@param postalCode tablica znaków zawierająca kod pocztowy
*@param city tablica znaków zawierająca nazwę miasta
*/
void fillAddress(struct Address *address, char street[], char homeNumber[], char postalCode[], char city[]);

/** Funkcja prosi o i odczytuje dane adresowe z konsoli oraz przypisuje je do adresu.
*@param address wskaźnik na adres do którego będą przekazane dane
*/
void readDataAddress(struct Address *address);

/** Funkcja prosi o i odczytuje nowe dane adresowe do edycji z konsoli oraz przypisuje je do adresu.
*@param address wskaźnik na adres do który będzie edytowany
*/
void editAddress(struct Address *address);

#endif //INVOICE_ADDRESS_H
