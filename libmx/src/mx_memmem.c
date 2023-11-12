#include "libmx.h"

void* mx_memmem(const void*big, size_t big_len, const void*little, size_t little_len) {
    if (little_len == 0)
        return (void*)big;

    if (big == NULL || little == NULL)
        return NULL;

    if(big_len < little_len || little_len < 0 || big_len <= 0)
        return NULL;

    unsigned char* t1 = (unsigned char*)big;
    unsigned char* t2 = (unsigned char*)little;
    
    for (size_t i = 0; i <= big_len - little_len ; i++) {
        if (mx_memcmp(t1 + i, t2, little_len) == 0)
            return (void *) (t1 + i);
    }

    return NULL;
}

