#include "libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) 
        return -1;

    if (*str == '\0') 
        return 0;

    int words = 0;

    if (str[0] != c)
        words = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != c && (str[i - 1] == c && i != 0))
            words++;
    }

    return words;
}

