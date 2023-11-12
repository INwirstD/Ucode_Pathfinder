#include "libmx.h"

char *mx_file_to_str(const char *filename) {

	if (filename == NULL)
		return NULL;

	int fold = open(filename, O_RDONLY);

	if (fold == -1)
		return NULL;

	int size = 0;
	char h;

	while(read(fold, &h, 1) != 0) {
		size++;
	}

    if (size == 0) {
        close(fold);
        return NULL;
    }

    close(fold);
	char *str = mx_strnew(size);

    if (str == NULL) {
        close(fold);
        return NULL;
    }

	int i = 0;
    fold = open(filename, O_RDONLY);

	while(read(fold, &h, 1) != 0) {
		str[i] = h;
		i++;
	}

	if (close(fold) == -1) {
        free(str);
        return NULL;
    }

	str[i] = '\0';
	return str;
}

