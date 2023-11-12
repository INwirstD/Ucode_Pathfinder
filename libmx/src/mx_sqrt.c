#include "libmx.h"

int mx_sqrt(int x){
    if (x < 0) {
        return 0;
    }

    if (x == 0) {
        return 0;
    }

    int result = x / 2;

    while (result * result > x) {
        result = (result + x / result) / 2;
    }

    if (result * result == x) {
        return result;
    }
    else {
        return 0;
    }
}
