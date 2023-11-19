#include "libmx.h"

char *mx_itoa(int number) {
    int temp = number;
    int length = 1;

    while (temp /= 10) {
        length++;
    }

    char *result = (char *)malloc((length + 1) * sizeof(char));

    if (result == NULL) {
        return NULL;
    }

    if (number < 0) {
        result[0] = '-';
        number = -number;
    }

    for (int i = length - 1; i >= 0; i--) {
        result[i] = (number % 10) + '0';
        number /= 10;
    }

    result[length] = '\0'; 

    return result;
}


