#include "libmx.h"

char *mx_strdup(const char *str) {
    if (str == NULL || *str == '\0') {
        return NULL;
    }

    size_t str_len = mx_strlen(str);
    char *dup = mx_strnew(str_len + 1); 

    if (dup == NULL) {
        return NULL;
    }

    mx_strcpy(dup, str);

    return dup;
}
