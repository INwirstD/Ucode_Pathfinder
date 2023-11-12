#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {

    if(src == NULL || dst == NULL)
        return NULL;    

    unsigned char *tmp1 = (unsigned char *) dst;
    unsigned char *tmp2 = (unsigned char *) src;

    for (size_t i = 0; i < n; i++)
        tmp1[i] = tmp2[i];
        
    return dst;
}
