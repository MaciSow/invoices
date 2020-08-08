/** @file */

#ifndef INVOICE_INPUT_H
#define INVOICE_INPUT_H

/** Funkcja odczytuje dane z pliku i na ich podstawie tworzy jednokierunkową listę faktur.
*@param invoiceList wskaźnik na wskaźnik na głowę jednokierunkowej listy faktur
*@param PATH ścieżka do folderu z plikiem do odczytu, gdy "" to odczyt z folderu w którym jest program
*@param fileName nazwa pliku do odczytu (wymagane rozszerzenie - ".txt")
*/
void readDataFromFile(struct Invoice **invoiceList, const char *PATH, char *fileName);

/** Funkcja odczytuje dane wyprowadzone na konsolę i zapisuje je do przekazanego stringa.
*@param target string do którego będą zapisane dane odczytane przez funkcję
*@param length maksymalna długość zapisywanych w stringu danych
*/
void readLine(char *target, int length);

/** Funkcja odczytuje z konsoli liczbę całkowitą.
*@return odczytana liczba całkowita
*/
int readInteger();

/** Funkcja odczytuje liczbę rzeczywistą z konsoli, w przypadku błędnych danych prosi o ponowne podanie liczby.
*@return odczytana liczba rzeczywista
*/
float readNumber();

/** Funkcja odczytuje liczbę rzeczywistą z konsoli, w przypadku błędnych danych prosi o ponowne podanie liczby.
*@return odczytana liczba rzeczywista podana w procentach
*/
float readPercentage();

/** Funkcja odczytuje datę z konsoli w odpowiednim formacie (dd.mm.rrrr).w przypadku błędnych danych prosi o ponowne podanie daty.
*@return odczytana data jako string
*/
char *readDate();

/** Funkcja odczytuje liczbę całkowitą, w przypadku błędnych danych prosi o ponowne podanie liczby.
*@param start początek przedziału z jakiego ma być liczba
*@param end koniec przedziału z jakiego ma być liczba
*@return odczytana liczba całkowita
*/
int readSelectOption(int start, int end);

/** Funkcja odczytuje wyniki wyboru [Y/n] gdzie domyślną wartością jest "Y".
*@param text tekst jaki ma być wyświetlony przed poproszeniem o wybór
*@return 1 dla "Y" (zgody), 0 dla "n" (niezgody)
*/
int readYesOrNoOption(char text[]);

#endif //INVOICE_INPUT_H
