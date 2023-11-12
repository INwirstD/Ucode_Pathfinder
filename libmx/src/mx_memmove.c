#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {

    if(src == NULL)
        return NULL;

    unsigned char *t1 = malloc(len);
    unsigned char *d = dst;
    const unsigned char *s = src;

    if (d == s || len == 0) {
        return dst;
    }

    t1 = mx_memcpy(t1, src, len);
    dst = mx_memcpy(dst, t1, len);
    free(t1);
    return dst;
}
