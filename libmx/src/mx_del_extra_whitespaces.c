#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) {
        return NULL; 
    }

    const char *start = str;
    const char *end = str;

    while (*start && mx_isspace(*start)) {
        start++;
    }

    while (*end) {
        if (!mx_isspace(*end)) {
            end = end + 1;
        } else {
            while (mx_isspace(*end)) {
                end = end + 1;
            }
            if (*end != '\0') {
                end = end - 1;
                break;
            }
        }
    }

    size_t newStrLength = end - start + 1;

    if (newStrLength == 0) {
        return NULL; 
    }

    char *newStr = (char *)malloc(newStrLength + 1);

    if (newStr == NULL) {
        return NULL; 
    }

    for (size_t i = 0; i < newStrLength; i++) {
        newStr[i] = start[i];
    }

    newStr[newStrLength] = '\0';
    return newStr;
}
