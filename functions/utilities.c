/** @file */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
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
}

void cutString(char *string, int length) {
    char *cutString = malloc(length);
    memset(cutString, '\0', length);

    for (int i = 0; i < length - 1; ++i) {
        cutString[i] = string[i];
    }

    cutString[length - 1] = '\0';
    strcpy(string, cutString);
    free(cutString);
}

char *getCurrentDate(char dateFormat[]) {
    time_t now;
    time(&now);

    char *date = malloc(11);
    memset(date, '\0', 11);

    struct tm local = *localtime(&now);
    strftime(date, 11, dateFormat, &local);

    return date;
}

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
}

int isNegative(char string[]) {
    float number = strtof(string, NULL);

    return number > 0 ? 0 : 1;
}

char *concatenationStrings(char a[], char b[]) {
    char *string = malloc(150);
    memset(string, '\0', 150);

    strcat(string, a);
    strcat(string, " ");
    strcat(string, b);

    return string;
}


int isValidDateFormat(const char *date) {
    int partDate;

    for (int i = 0; i < 10; ++i) {
        partDate = date[i] - '0';

        if ((i == 2 || i == 5) && partDate != -2) {
            return 0;
        }

        if ((partDate < 0 || partDate > 9) && (i != 2 && i != 5)) {
            return 0;
        }
    }

    return 1;
}

int isValidDatePart(char *date, int start, int length, int min, int max) {
    char partDateString[5] = {};
    int partDate;

    strncpy(partDateString, date + start, length);
    partDate = atoi(partDateString);

    return (partDate >= min && partDate <= max) ? 1 : 0;

}

char *formatAccountNumber(const char *accountNumber) {
    char *correctFormat = malloc(40);
    memset(correctFormat, 0, 40);

    int index = 0;

    for (int i = 0; i < 26; ++i) {
        correctFormat[index] = accountNumber[i];

        if (i % 4 == 1) {
            index++;
            correctFormat[index] = ' ';
        }
        index++;
    }

    return correctFormat;
}