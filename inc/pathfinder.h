#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "libmx.h"

typedef struct s_graph {
    int count;
    int counts;
    char **peaks;
    int **edges;
}              t_graph;

typedef struct s_islands {
    bool check;
    int sub_islands_weight;
    int index;
    t_list *pr_island;
}              t_islands;

int secure_node(t_graph *graph, char *node);
bool check_name(const char *node);
int fill_graph(int fd, t_graph *graph);
void remove_graph(t_graph *graph);

int parse_line_data(int fd, char **node1, char **node2, int *weight);
t_graph *parse_file(const char *filename);
void print_path(t_graph *graph);

t_islands *find_shortest_path(t_graph *graph, int start);
bool compare_peaks(void *node1, void *node2, void *node);
t_list *restore_path(t_islands *node);

void mx_printerr(const char *s);
void mx_clear_list(t_list **list);
bool mx_is_positive_integer(const char *str);

void init_node(t_islands *node, int index);
void update_neighbors(t_graph *graph, t_islands *peaks, int current);
void update_path_weight(t_islands *neighbor, t_islands *current, int edge);
int find_next_node(t_islands *peaks, int count); 

#endif



