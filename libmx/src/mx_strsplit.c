#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s)
        return NULL;

    int word_length = mx_count_wordssec(s, c);
    char **arr = (char **)malloc((word_length + 1) * sizeof(char *));
    int i = 0;

    while (*s != '\0') {
        if (*s != c) {
            word_length = 0;
            while (s[word_length] && s[word_length] != c)
                word_length++;

            arr[i] = mx_strndup(s, word_length);
            s += word_length;
            i++;
        } else {
            s++;
        }
    }
    
    arr[i] = NULL;
    return arr;
}
