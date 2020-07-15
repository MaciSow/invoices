#ifndef INVOICE_UTILITIES_H
#define INVOICE_UTILITIES_H

char *cutString(const char *string, int length);

int checkString(const char *string, char *value);

char *getCurrentDate(char dateFormat[]);

char *getFutureDate(char dateFormat[],int weeks);

int isNegative(char string[]);


char *concatenationStrings(char a[], char b[]);

int isValidDateFormat(const char *date);

int isValidDatePart(char *date, int start, int length, int min, int max);


#endif //INVOICE_UTILITIES_H
