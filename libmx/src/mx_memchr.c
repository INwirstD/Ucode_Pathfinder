#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {

    if(s == NULL)
        return NULL;

    unsigned char* src = (unsigned char*)s;
    
    for(int i = n - 1; i >= 0; i--) {
        if((int)src[i] == c)
        return (void*)(src + i);
    }
    return NULL;
}

