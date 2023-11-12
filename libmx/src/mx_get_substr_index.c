#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -2;
    }

    int sub_len = mx_strlen(sub);
    int j;

    for (int i = 0; i <= mx_strlen(str) - sub_len; i++) {
        
        for (j = 0; j < sub_len; j++) {
            if (str[i + j] != sub[j]) {
                break;
            }
        }

        if (j == sub_len) {
            return i; 
        }
    }
    return -1;
}

