#include "libmx.h"

void mx_printstr(const char *s) {
    int length = mx_strlen(s);

    write(STDOUT_FILENO, s, length);
}
