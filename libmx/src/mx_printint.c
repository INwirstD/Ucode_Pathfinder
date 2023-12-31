#include "libmx.h"

void mx_printint(int n) {
    if (n == 0)
        mx_printchar('0');
    else if (n == -2147483648) {
        write(1, "-2147483648", 11);
    } 
    else if (n == 2147483647) {
        write(1, "2147483647", 10);
    } 
    else if (n < 0) {
        n = -n;
        mx_printchar('-');
        if (n >= 10) {
            mx_printint(n / 10);
        }
        mx_printchar(n % 10 + '0');
    } 
    else {
        if (n >= 10) {
            mx_printint(n / 10);
        }
        mx_printchar(n % 10 + '0');
    }
}
