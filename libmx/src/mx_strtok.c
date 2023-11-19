#include "libmx.h"

char *mx_strtok(char *str, const char delim) {
    static char *nextToken = NULL;

    if (str != NULL) {
        nextToken = str;
    } else if (nextToken == NULL) {
        return NULL;
    }

    char *tokenStart = nextToken;
    while (*nextToken != '\0' && *nextToken != delim) {
        nextToken++;
    }

    if (*nextToken == delim) {
        *nextToken = '\0';
        nextToken++;
    } else if (*nextToken == '\0') {
        nextToken = NULL; // Indicates the end of the string
    }

    return tokenStart;
}
