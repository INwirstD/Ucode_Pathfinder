#include "libmx.h"

int mx_atoi(const char *str, int *number) {
    if (str == NULL || number == NULL) {
        return 0; 
    }

    int result = 0;
    int sign = 1;


    while (*str == ' ' || (*str >= '\t' && *str <= '\r')) {
        str++;
    }


    if (*str == '+' || *str == '-') {
        sign = (*str++ == '-') ? -1 : 1;
    }


    while (mx_isdigit(*str)) {
        int digit = *str - '0';


        if (result > (2147483647 - digit) / 10) {
            return 0; 
        }

        result = result * 10 + digit;
        str++;
    }

    *number = result * sign;

    return 0;  
}

