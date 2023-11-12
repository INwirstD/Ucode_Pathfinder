#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (mx_strlen(needle) == 0)
        return (char *) haystack;

    if (mx_strlen(haystack) < mx_strlen(needle))
        return NULL;

    while (*haystack != '\0') {
        char *tmp = mx_strchr(haystack, haystack[0]);

        if (mx_strncmp(tmp, needle, mx_strlen(needle)) == 0) {
            return (char *)haystack;
        }
        
        haystack++;
    }

    return NULL;
}
