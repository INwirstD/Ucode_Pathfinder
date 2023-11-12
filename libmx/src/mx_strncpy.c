#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    char* oPurpose = dst;

    while (len > 0 && *src != '\0') {
        *dst++ = *src++;
        len--;
    }

    while (len > 0) {
        *dst++ = '\0';
        len--;
    }

    return oPurpose;
}

