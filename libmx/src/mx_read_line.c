#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (lineptr == NULL || buf_size == 0 || fd < 0)
        return -2;

    char *res = mx_strnew(0);
    ssize_t bytes_read;
    char *buf = mx_strnew(buf_size);

    while ((bytes_read = read(fd, buf, 1)) > 0) {
        if (buf[0] == delim) {
            mx_strdel(&buf);

            return mx_strlen(*lineptr = res);
        }

        char *temp = mx_strjoin(res, buf);
        mx_strdel(&res);
        res = temp;
    }

    mx_strdel(&buf);

    if(bytes_read < 0) {
        mx_strdel(&res);
        return -2;
    }
    if (bytes_read == 0) {
        *lineptr = res;
        return  -1;
    }
    
    *lineptr = res;
    return mx_strlen(*lineptr);
}

