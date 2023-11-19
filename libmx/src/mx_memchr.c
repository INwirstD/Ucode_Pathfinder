#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *p = (unsigned char *)s;

    for (size_t i = 0; i < n; i++, p++) {
        if (*p == (unsigned char)c) {
            return p;
        }
    }

    return NULL;
}

