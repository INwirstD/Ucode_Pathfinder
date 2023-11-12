#include "libmx.h"

char *mx_itoa(int number) {
    int temp = number;
    int length = 0;

    if (temp == 0) {
        length = 1;
    } else if (temp < 0) {
        temp = -temp;
        length++;
    }

    while (temp > 0) {
        temp /= 10;
        length++;
    }

    char *str = (char *)malloc(length + 1);

    if (str == NULL) {
        return NULL; 
    }

    str[length] = '\0'; 

    if (number < 0) {
        number = -number;
        str[0] = '-';
    } else if (number == 0) {
        str[0] = '0';
    }

    for (int i = length - 1; i > 0; i--) {
        str[i] = '0' + (number % 10);
        number /= 10;
    }

    return str;
}

