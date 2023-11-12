#include "../inc/pathfinder.h"

static void print_error(const char *error_message) {
    mx_printstr("error: ");
    mx_printstr(error_message);
    mx_printstr("\n");
}

bool mx_parse_file(const char *filename, t_graph **graph) {
    int fd = open(filename, O_RDONLY);
    char *file_content = NULL;

    if (fd < 0) {
        mx_printstr("file ");
        mx_printstr(filename);
        mx_printstr(" does not exist");
        return false;
    }

    file_content = mx_file_to_str(filename);

    if (!file_content) {
        close(fd);
        print_error("file is empty");
        return false;
    }

    char **lines = mx_strsplit(file_content, '\n');
    mx_strdel(&file_content);

    // Validate and parse the number of islands
    if (!mx_parse_num_islands(lines[0], graph)) {
        close(fd);
        mx_del_strarr(&lines);
        return false;
    }

    // Add more parsing logic for bridges and distances

    close(fd);
    mx_del_strarr(&lines);
    return true;
}

bool mx_parse_num_islands(const char *line, t_graph **graph) {
    if (!mx_is_number(line) || mx_atoi(line) <= 0) {
        print_error("line 1 is not valid");
        return false;
    }

    (*graph) = (t_graph *)malloc(sizeof(t_graph));

    if (!(*graph)) {
        print_error("memory allocation failed");
        return false;
    }

    (*graph)->num_islands = mx_atoi(line);

    return true;
}

bool mx_is_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}