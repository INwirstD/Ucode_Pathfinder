#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *hexString = NULL;
    int hexStringLength = 0;
    unsigned long temp = nbr;

    while (temp > 0) {
        temp /= 16;
        hexStringLength++;
    }

    if (hexStringLength == 0) {
        hexStringLength = 1;
    }

   
    hexString = (char *) malloc(hexStringLength + 1);

    if (hexString == NULL) {
        return NULL; 
    }

    
    for (int i = hexStringLength - 1; i >= 0; i--) {
        int remainder = nbr % 16;
        if (remainder < 10) {
            hexString[i] = '0' + remainder;
        } else {
            hexString[i] = 'a' + (remainder - 10);
        }
        nbr /= 16;
    }

    hexString[hexStringLength] = '\0'; 
    return hexString;
}

