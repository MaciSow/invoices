#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utilities.h"

int checkString(const char *string, char *value) {
    if (!strlen(value)) {
        return 0;
    }

    for (int i = 0; i < strlen(value); i++) {
        if (string[i] != value[i]) {
            return 0;
        }
    }
    return 1;
};

char *cutString(const char *string, int length) {
    char *cutString = malloc(length);
    memset(cutString, '\0', length);

    for (int i = 0; i < length - 1; ++i) {
        cutString[i] = string[i];
    }

    cutString[length - 1] = '\0';

    return cutString;
}

char *getCurrentDate(char dateFormat[]) {
    time_t now;
    time(&now);

    char *date = malloc(11);
    memset(date, '\0', 11);

    struct tm local = *localtime(&now);
    strftime(date, 11, dateFormat, &local);

    return date;
};

char *getFutureDate(char dateFormat[], int weeks) {
    time_t now;
    time(&now);

    char *date = malloc(11);
    memset(date, '\0', 11);

    struct tm local = *localtime(&now);

    local.tm_sec += weeks * 604800;

    mktime(&local);

    strftime(date, 11, dateFormat, &local);

    return date;
};

int isNegative(char string[]) {
    float number = strtof(string, NULL);
    return number > 0 ? 0 : 1;
}

void printSeparator(int n, char separator ) {
    char * dest = malloc(n+1);
    memset(dest, separator, n);
    dest[n] = '\0';
    printf("%s\n", dest);
    free(dest);
}

char *concatenationStrings(char a[], char b[]) {
    char *string = malloc(150);
    memset(string, '\0', 150);

    strcat(string, a);
    strcat(string, " ");
    strcat(string, b);
    strcat(string, "\0");

    return string;
}