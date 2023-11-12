#include "libmx.h"

char *mx_strchr(const char *s, int c) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (*s != c)
            s++;
        else
            return (char*) s;
    }
    
    return NULL;
}
