#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdbool.h>
#include <stdlib.h>
#include "libmx.h"

typedef struct s_edge {
    int island1;
    int island2;
    int length;
    struct s_edge *next;
} t_edge;

typedef struct s_graph {
    int num_islands;
    t_edge **edges;
} t_graph;            

bool mx_parse_file(const char *filename, t_graph **graph);
bool mx_parse_num_islands(const char *line, t_graph **graph);
bool mx_is_number(const char *str);



#endif