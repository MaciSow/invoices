/** @file */

#ifndef INVOICE_OUTPUT_H
#define INVOICE_OUTPUT_H

/** Funkcja zapisuje dane do pliku.
*@param invoiceList wskaźnik na jednokierunkową listę faktur
*@param PATH ścieżka do folderu z plikiem do zapisu, gdy "" to zapis do folderu w którym jest program
*@param fileName nazwa pliku do zapisu (wymagane rozszerzenie - ".txt")
*/
void saveDataToFile(struct Invoice *invoiceList, const char *PATH, char *fileName);

/** Funkcja zapisuje do pliku dane osoby.
*@param person wskaźnik na osobę
*@param fptr wskaźnik na plik
*/
void filePrintPersonData(struct Person *person, FILE *fptr);

/** Funkcja zapisuje do pliku dane adresowe.
*@param address wskaźnik na adres
*@param fptr wskaźnik na plik
*/
void filePrintAddress(struct Address *address, FILE *fptr);

/** Funkcja zapisuje do pliku dane towaru/usługi.
*@param ware wskaźnik na towar/usługę
*@param fptr wskaźnik na plik
*/
void filePrintWare(struct Ware *ware, FILE *fptr);

/** Funkcja zapisuje do pliku separator.
*@param n długość separatora
*@param separator znak z jakiego ma być zbudowany separator
*@param fptr wskaźnik na plik
*/
void filePrintSeparator(int n, char separator, FILE *fptr);

/** Funkcja wypisuje separator do konsoli.
*@param n długość separatora
*@param separator znak z jakiego ma być zbudowany separator
*/
void printSeparator(int n, char separator);

/** Funkcja wypisuje menu do konsoli.
*/
void printMenu();

/** Funkcja wypisuje opcje do konsoli.
*/
void printOptions();

#endif //INVOICE_OUTPUT_H
