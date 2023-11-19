#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL) {
        return NULL; 
    }

    size_t len1 = (s1 == NULL) ? 0 : mx_strlen(s1);
    size_t len2 = (s2 == NULL) ? 0 : mx_strlen(s2);

    char *result = (char *)malloc(len1 + len2 + 1); 

    if (result == NULL) {
        return NULL; 
    }

    if (s1 != NULL) {
        mx_strcpy(result, s1);
    }

    if (s2 != NULL) {
        mx_strcpy(result + len1, s2);
    }

    return result;
}

