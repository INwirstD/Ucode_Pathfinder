#include "../inc/pathfinder.h"

bool mx_is_file_empty(const char *filename) {
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        return true; 
    }

    char *line = NULL;
    size_t buf_size = 1; 

    int bytes_read = mx_read_line(&line, buf_size, '\n', fd);

    close(fd);
    mx_strdel(&line);  

    return (bytes_read == -1);
}

t_graph *parse_file(const char *filename) {
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        mx_printerr("error: file ");
        mx_printerr((char*)filename);
        mx_printerr(" does not exist\n");
        return 0;
    }

    if (mx_is_file_empty(filename)) {
        mx_printerr("error: file ");
        mx_printerr((char*)filename);
        mx_printerr(" is empty\n");
        return 0;
    }

    //line count
    char *line_one = NULL;
    int result_one = mx_read_line(&line_one, 1, '\n', fd);

    if (result_one < 0) {
        return 0;
    }

    int count = 0;
    mx_atoi(line_one, &count);
    

    //cheking 
    if (count <= 0 || !mx_is_positive_integer(line_one)) {
        mx_printerr("error: line 1 is not valid\n");
        return NULL;
    }
    
    mx_strdel(&line_one);

    //graph
    int counts = count;
    t_graph *graph = (t_graph *)malloc(sizeof(t_graph));
    graph->count = 0;
    graph->counts = counts;
    graph->peaks = (char **)malloc(sizeof(char*) * counts);
    graph->edges = (int **)malloc(sizeof(int*) * counts);

    for (int i = 0; i < counts; i++) {
        graph->peaks[i] = NULL;
        graph->edges[i] = (int *)malloc(sizeof(int) * counts);

        for (int j = 0; j < counts; j++) {
            graph->edges[i][j] = -1;
        }
    }

    int result = fill_graph(fd, graph);

    if (result == 0 && !(graph->count == graph->counts)) {
        mx_printerr("error: invalid number of islands\n");
        result = -1;
    }

    long check_sum = 0;

    for (int i = 0; i < graph->count; i++) {
        for (int j = i + 1; j < graph->count; j++) {
            check_sum += graph->edges[i][j];
        }
    }


    if (result == 0 && check_sum > INT_MAX) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        result = -1;
    }

    if (result < 0) {
        remove_graph(graph);
        graph = NULL;
    }

    close(fd);
    return graph;
}

