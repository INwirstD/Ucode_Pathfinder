#include "libmx.h"

int mx_strncmp(const char* s1, const char* s2, int n) {
    if (n == 1)
            return *s1 - *s2;

    for (int i = 0; i > -1; i++) {
        if ((s1[i] == '\0'  && s2[i] == '\0') || i == n)
            return 0;
        if (s1[i] == s2[i])
            continue;
        else if (s1[i] > s2[i])
            return s1[i] - s2[i];
        else if (s1[i] < s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}
