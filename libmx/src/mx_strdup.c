#include "libmx.h"

char *mx_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    char *duplicate = (char *)malloc((length + 1) * sizeof(char));

    if (duplicate == NULL) {
        return NULL; 
    }

    for (int i = 0; i <= length; i++) {
        duplicate[i] = str[i];
    }

    return duplicate;
}
