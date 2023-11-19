#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 0;
    }

    const char *filename = argv[1];
    t_graph *graph = NULL;
    graph = parse_file(filename);
    print_path(graph);

}

