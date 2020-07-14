#ifndef INVOICE_UTILITIES_H
#define INVOICE_UTILITIES_H

char *cutString(const char *string, int length);

int checkString(const char *string, char *value);

char *getCurrentDate(char dateFormat[]);

char *getFutureDate(char dateFormat[],int weeks);

int isNegative(char string[]);

void printSeparator(int n, char separator );

char *concatenationStrings(char a[], char b[]);

#endif //INVOICE_UTILITIES_H
