#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1;
    int iterations = 0;

    while (left <= right) {
        int middle = (left + right) / 2;
        int cmp = mx_strcmp(arr[middle], s);

        iterations++;

        if (cmp == 0) {
            *count = iterations;
            return middle;
        }
        else if (cmp < 0) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    *count = 0;
    return -1;
}
