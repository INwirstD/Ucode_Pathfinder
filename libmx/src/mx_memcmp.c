#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *t1 = (unsigned char *) s1;
    const unsigned char *t2 = (unsigned char *) s2;

    if (n == 0)
        return 0;

    if (s1 == NULL && s2 == NULL) {
        return 0;
    }
    else if (s1 == NULL) {
        return 0 - t2[0];
    }
    else if (s2 == NULL) {
        return t1[0];
    }

    for (size_t i = 0; i < n; i++) {
        if (t1[i] != t2[i])
            return t1[i] - t2[i];
    }
    
    return 0;
}
