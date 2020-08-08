/** @file */

#ifndef INVOICE_UTILITIES_H
#define INVOICE_UTILITIES_H

/** Funkcja sprawdza czy początek stringa zawiera przekazaną wartość.
*@param string string w którego początek będzie sprawdzany
*@param value wartość zapisana w stringu jako podstawa do sprawdzenia
*/
int checkString(const char *string, char *value);

/** Funkcja przycina przekazany string na podaną długość i daje na końcu znak końca stringa ("\0").
*@param string string do przycięcia
*@param length długość do jakiej ma być przycięty string
*/
void cutString(char *string, int length);

/** Funkcja pobiera aktualną datę z systemu.
*@param dateFormat format w jakim ma być zwrócona data
*@return aktualna data jako łańcuch znaków
*/
char *getCurrentDate(char dateFormat[]);

/** Funkcja do aktualnej daty dodaje przekazaną ilość tygodni.
*@param dateFormat format w jakim ma być zwrócona data
*@param weeks ilość tygodni jaka ma być dodana do daty
*@return obliczona data jako łańcuch znaków
*/
char *getFutureDate(char dateFormat[], int weeks);

/** Funkcja sprawdza czy przekazany string jest liczbą ujemną.
*@param string tablica znaków do sprawdzenia
*@return 1 jeśli liczba ujemna, 0 w przeciwnym razie
*/
int isNegative(char string[]);

/** Funkcja łączy przekazane stringi i oddziela je " " między sobą.
*@param a string do połączenia
*@param b string do połączenia
*@return string połączone wyrazy oddzielone " "
*/
char *concatenationStrings(char a[], char b[]);

/** Funkcja sprawdza czy przekazana data jest w odpowiednim formacie.
*@param date data do sprawdzenia zapisana jako string
*@return 1 jeśli format daty jest poprawny, 0 w przeciwnym razie
*/
int isValidDateFormat(const char *date);

/** Funkcja sprawdza czy część przekazanej daty jest poprawna.
*@param date data do sprawdzenia zapisana jako string
*@param start początek przedziału do sprawdzenia
*@param end koniec przedziału do sprawdzenia
*@param min wartość minimalna jaka może być w danym przedziale
*@param max wartość maksymalna jaka może być w danym przedziale
*@return 1 jeśli wartość w danej części daty jest poprawna, 0 w przeciwnym razie
*/
int isValidDatePart(char *date, int start, int length, int min, int max);

/** Funkcja formatuje przekazany numer konta(" " po grupie 4 cyfr).
*@param accountNumber numer konta do formatowania zapisany jako string
*@return sformatowany numer konta jako string
*/
char *formatAccountNumber(const char *accountNumber);

#endif //INVOICE_UTILITIES_H
