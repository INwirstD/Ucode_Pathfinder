#include <stdlib.h>

void *mx_memalloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr != NULL) {
        // Initialize the allocated memory to zero
        for (size_t i = 0; i < size; i++) {
            *((char*)ptr + i) = 0;
        }
    }

    return ptr;
}
