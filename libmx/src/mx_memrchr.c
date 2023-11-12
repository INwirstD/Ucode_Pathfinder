#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    if(s == NULL)
        return NULL;

    const unsigned char *t1 = (const unsigned char *) s;
    unsigned char stop = (unsigned char) c;

    for (size_t i = n; i > 0; i--) {
        if (t1[i] == stop)
            return (void *) &t1[i];
    }
    return NULL;
}
