#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size < 1 || buf_size > 2147483647 || fd <= 0 || lineptr == NULL) {
        return -2;
    }

    static char *buffer = NULL;
    char *str = NULL;
    int end_size = 0;

    if (buffer != NULL) {
        char *delim_sec = mx_strchr(buffer, delim);

        if (delim_sec != NULL) {
            *delim_sec = '\0';
            end_size = mx_strlen(buffer);
            str = mx_strndup(buffer, end_size);
            buffer = mx_strdup(delim_sec + 1);

            if (mx_strlen(buffer) == 0) {
                mx_strdel(&buffer);
            }

            *lineptr = str;
            return end_size;
        }
        else {
            end_size = mx_strlen(buffer);
            str = mx_strdup(buffer);
            mx_strdel(&buffer);

            *lineptr = str;
            return end_size;
        }
    }

    char *buf = mx_strnew(buf_size);
    ssize_t check_in_read = -1;

    while ((check_in_read = read(fd, buf, buf_size)) > 0) {
        buf[check_in_read] = '\0';
        char *delim_sec = mx_strchr(buf, delim);

        if (delim_sec != NULL) {
            *delim_sec = '\0';
            end_size += mx_strlen(buf);
            str = mx_strjoin(str, buf);
            buffer = mx_strdup(delim_sec + 1);

            if (mx_strlen(buffer) == 0) {
                mx_strdel(&buffer);
            }

            *lineptr = str;
            break;
        }
        else {
            end_size += mx_strlen(buf);
            str = mx_strjoin(str, buf);
        }
    }

    mx_strdel(&buf);

    if (check_in_read == -1) {
        mx_strdel(&str);
        mx_strdel(&buffer);
        return -2;
    }

    if (str == NULL) {
        return -1;
    }

    *lineptr = str;

    return end_size;
}

