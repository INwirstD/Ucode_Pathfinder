#include "libmx.h"

int mx_count_words(char **arr) {
    if (arr == NULL)
        return -1;

    int count = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        // Consider each non-empty string as a word
        if (mx_strlen(arr[i]) > 0)
            count++;
    }

    return count;
}

