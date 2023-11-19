#include "../inc/pathfinder.h"

t_islands *find_shortest_path(t_graph *graph, int start) {
    t_islands *peaks = (t_islands *)malloc(sizeof(t_islands) * graph->count);

    for (int i = 0; i < graph->count; i++) {
        init_node(&peaks[i], i);
    }

    peaks[start].sub_islands_weight = 0;
    int current = start;

    while (current != -1) {
        peaks[current].check = true;

        update_neighbors(graph, peaks, current);

        current = find_next_node(peaks, graph->count);
    }

    return peaks;
}

void init_node(t_islands *node, int index) {
    node->check = false;
    node->sub_islands_weight = -1;
    node->index = index;
    node->pr_island = NULL;
}

void update_neighbors(t_graph *graph, t_islands *peaks, int current) {
    for (int i = 0; i < graph->count; i++) {
        int edge = graph->edges[current][i];

        if (!peaks[i].check && edge != -1) {
            update_path_weight(&peaks[i], &peaks[current], edge);
        }
    }
}

void update_path_weight(t_islands *neighbor, t_islands *current, int edge) {
    int sub_islands_weight = current->sub_islands_weight + edge;

    if (neighbor->sub_islands_weight == -1 || sub_islands_weight <= neighbor->sub_islands_weight) {
        if (sub_islands_weight < neighbor->sub_islands_weight) {
            mx_clear_list(&neighbor->pr_island);
        }

        neighbor->sub_islands_weight = sub_islands_weight;
        mx_push_back(&neighbor->pr_island, current);
    }
}

int find_next_node(t_islands *peaks, int count) {
    int current = -1;

    for (int i = 0; i < count; i++) {
        if (!peaks[i].check && peaks[i].sub_islands_weight != -1) {
            if (current == -1 || peaks[i].sub_islands_weight < peaks[current].sub_islands_weight) {
                current = i;
            }
        }
    }

    return current;
}


