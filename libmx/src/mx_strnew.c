#include "libmx.h"

char *mx_strnew(const int size) {
    if (size < 0) 
        return NULL;

    char *mem = (char*) malloc((size + 1) * sizeof(char));

    if(mem == NULL)
        return NULL;

    if (size < 0)
        return NULL;
        
    for (int i = 0; i <= size; i++)
        mem[i] = '\0';

    return mem;
}

