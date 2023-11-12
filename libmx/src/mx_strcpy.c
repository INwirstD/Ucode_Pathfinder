#include "libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    char *oPurpose = dst;

    while (*src != '\0') {
        *dst  = *src;
        src++;
        dst++;
    }

    *dst = '\0';
    return oPurpose;
}
