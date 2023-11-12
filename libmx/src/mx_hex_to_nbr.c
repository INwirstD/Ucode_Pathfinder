#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    int i = 0;

    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
        i = 2;
    }

    while (hex[i] != '\0') {
        char c = hex[i];
        unsigned long digit;

        if (c >= '0' && c <= '9') {
            digit = c - '0';
        }
        else if (c >= 'A' && c <= 'F'){
            digit = c - 'A' + 10;
        }
        else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        }
        else {
            return 0;
        }

        result = result * 16 + digit;
        i++;
    }

    return result;
}
