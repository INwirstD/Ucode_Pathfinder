#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,int c, size_t n) {
    if (src == NULL) {
        return NULL;
    }

    unsigned char* t1 = (unsigned char*)src;
    unsigned char* t2 = (unsigned char*)dst;
    unsigned char stop = (unsigned char) c;

    while (n--) {
        *(t2++) = *(t1++);
        if((int)*(t2-1) == stop)
            return t2;
    }
    
    return NULL;
}

