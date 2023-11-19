#include "../inc/pathfinder.h"

int parse_line_data(int fd, char **node1, char **node2, int *weight) {
    int result = mx_read_line(node1, 1, '-', fd);

    if (result < 0) {
        return 0;
    }

    result = mx_read_line(node2, 1, ',', fd);

    if (result < 0) {
        mx_strdel(node1);
        return -1;
    }

    char *weight_buf = NULL;
    result = mx_read_line(&weight_buf, 1, '\n', fd);

    if (result < 0) {
        mx_strdel(node1);
        mx_strdel(node2);
        return -1;
    }

    mx_atoi(weight_buf, weight);
    mx_strdel(&weight_buf);

    if (!check_name(*node1) || !check_name(*node2)
        || mx_strcmp(*node1, *node2) == 0 || *weight <= 0) {
        mx_strdel(node1);
        mx_strdel(node2);

        return -1;
    }

    return 1;
}

int secure_node(t_graph *graph, char *node) {

    int index = -1;

    for (int i = 0; i < graph->count; i++) {
        if (mx_strcmp(node, graph->peaks[i]) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1 && !(graph->count == graph->counts)) {
        graph->peaks[graph->count] = mx_strdup(node);
        graph->edges[graph->count][graph->count] = 0;
        index = graph->count;
        graph->count++;
    }

    return index;
}

bool check_name(const char *node) {
    if (node == NULL || node[0] == '\0') {
        return false;
    }

    for (int i = 0; node[i] != '\0'; i++) {
        if (!((node[i] >= 'A' && node[i] <= 'Z') || (node[i] >= 'a' && node[i] <= 'z'))) {
            return false;
        }
    }

    return true;
}

int fill_graph(int fd, t_graph *graph) {
    int result;

    for (int i = 2;; i++) {
        char *node1 = NULL;
        char *node2 = NULL;
        int weight = 0;
        result = parse_line_data(fd, &node1, &node2, &weight);

        if (result <= 0) {
            if (result < 0) {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i));
                mx_printerr(" is not valid\n");
            }

            break;
        }

        int index1 = secure_node(graph, node1);
        int index2 = secure_node(graph, node2);

        if (index1 == -1 || index2 == -1) {
            mx_printerr("error: invalid number of islands\n");
            mx_strdel(&node1);
            mx_strdel(&node2);
            return -1;
            break;
        }

        if (graph->edges[index1][index2] != -1) {
            mx_printerr("error: duplicate bridges\n");
            mx_strdel(&node1);
            mx_strdel(&node2);
            return -1;
            break;
        }

        graph->edges[index1][index2] = weight;
        graph->edges[index2][index1] = weight;

        mx_strdel(&node1);
        mx_strdel(&node2);
    }

    return result;
}

void remove_graph(t_graph *graph) {
    for (int i = 0; i < graph->counts; i++) {
        mx_strdel(&graph->peaks[i]);
        free(graph->edges[i]);
    }

    free(graph->peaks);
    free(graph->edges);
    free(graph);
}

