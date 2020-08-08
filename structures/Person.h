#ifndef INVOICE_PERSON_H
#define INVOICE_PERSON_H

/**
	Struktura osoby.
*/
struct Person {
    char companyName[50];        ///< nazwa firmy
    char name[50];               ///< imię osoby
    char surname[50];            ///< nazwisko osoby
    char nip[11];                ///< nip
    char accountNumber[27];      ///< numer konta
    struct Address *address;     ///< wskaźnik na adres
};

/** Konstruktor wypełnia strukturę osoby domyślnymi danymi i alokuje pamięć na nią.
*@return wskaźnik na utworzoną strukturę osoby
*/
struct Person *createPerson();

/** Funkcja wypełnia strukturę osoby danymi.
*@param person wskaźnik na osobę
*@param address wskaźnik na adres
*@param companyName tablica znaków zawierająca nazwę firmy
*@param name tablica znaków zawierająca imię
*@param surname tablica znaków zawierająca nazwisko
*@param nip tablica znaków zawierająca nip
*@param accountNumber tablica znaków zawierająca numer konta
*/
void
fillPerson(struct Person *person, struct Address *address, char companyName[], char name[], char surname[], char nip[],
           char accountNumber[]);

/** Funkcja usuwa osobę wraz z jej adresem i zwalnia pamięć .
*@param person wskaźnik na osobę
*/
void deletePerson(struct Person *person);

/** Funkcja prosi o i odczytuje dane osobowe z konsoli oraz przypisuje je do osoby.
*@param person wskaźnik na osobę do której będą przekazane dane
*@param isSolder sprawdzenie czy osoba będzie sprzedawcą czy nabywcą
*/
void readDataPerson(struct Person *person, int isSolder);

/** Funkcja prosi o i odczytuje nowe dane osobowe do edycji z konsoli oraz przypisuje je do osoby.
*@param person wskaźnik na osobę do która będzie edytowana
*@param isSolder sprawdzenie czy osoba będzie sprzedawcą czy nabywcą
*/
void editPerson(struct Person *person, int isSolder);

/** Funkcja wyświetla podpisane dane sprzedawcy i nabywcy obok siebie.
*@param solder wskaźnik na osobę sprzedawcy
*@param buyer wskaźnik na osobę nabywcy
*/
void showPersonsTogether(struct Person *solder, struct Person *buyer);

/** Funkcja wyświetla dane sprzedawcy i nabywcy obok siebie.
*@param solder wskaźnik na osobę sprzedawcy
*@param buyer wskaźnik na osobę nabywcy
*/
void showPersonsInLine(struct Person *solder, struct Person *buyer);

/** Funkcja łączy nazwę firmy, imię i nazwisko osoby w jedną linie.
*@param person wskaźnik na osobę
*@return string zawierający połączone wszystkie dane z " " pomiędzy każdą
*/
char *getLinePerson(struct Person *person);

/** Funkcja sprawdza czy przekazana osoba posiada firmę czy jest osobą prywatną.
*@param person wskaźnik na osobę
*@return 1 jeśli posiada firmę, 0 w przeciwnym wypadku
*/
int isCompany(struct Person *person);

#endif //INVOICE_PERSON_H
