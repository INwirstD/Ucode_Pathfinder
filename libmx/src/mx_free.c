#include "libmx.h"

void mx_free(void *ptr) {
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;
    }
}
