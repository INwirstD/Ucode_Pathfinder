#include "../inc/pathfinder.h"


void print_path(t_graph *graph) {
    for (int i = 0; i < graph->count; i++) {
        t_islands *peaks = find_shortest_path(graph, i);

        for (int end = i + 1; end < graph->count; end++) {
            t_list *paths = restore_path(&peaks[end]);
            t_list *current_path = paths;

            while (current_path != NULL) {
                t_list *path = (t_list*)current_path->data;

                for (int i = 0; i < 40; i++) {
                    mx_printstr("=");
                }
                mx_printstr("\n");
                mx_printstr("Path: ");
                mx_printstr(graph->peaks[i]);
                mx_printstr(" -> ");
                mx_printstr(graph->peaks[end]);
                mx_printstr("\n");
                mx_printstr("Route: ");

                //route
                while (path != NULL) { 
                    t_islands *peaks = (t_islands *)path->data;

                    if (peaks->sub_islands_weight != 0) {
                        mx_printstr(" -> ");
                    }

                    mx_printstr(graph->peaks[peaks->index]);
                    path = path->next;
                }

                mx_printstr("\n");
                mx_printstr("Distance: ");
                // distance
                path = (t_list*)current_path->data;
                while (path != NULL && path->next != NULL) {
                    t_islands *node = (t_islands *)path->data;
                    t_islands *next_node = (t_islands *)path->next->data;

                    if (node->sub_islands_weight != 0) {
                        mx_printstr(" + ");
                    }

                    mx_printint(next_node->sub_islands_weight - node->sub_islands_weight);

                    if (node->sub_islands_weight != 0
                        && path->next->next == NULL) {
                        mx_printstr(" = ");
                        mx_printint(next_node->sub_islands_weight);
                    }

                    path = path->next;
                }

                mx_printstr("\n");
                mx_printstr("========================================");
                mx_printstr("\n");

                mx_clear_list(&path);
                current_path = current_path->next;
            }

            mx_clear_list(&paths);
        }

        for (int i = 0; i < graph->count; i++) {
            mx_clear_list(&peaks[i].pr_island);
        }

        free(peaks);

    }

    remove_graph(graph);
}

t_list *restore_path(t_islands *node) {
    if (node->sub_islands_weight == 0) {
        return mx_create_node(mx_create_node(node));
    }

    t_list *paths = NULL;
    t_list *pr_island = node->pr_island;
    
    mx_sort_list(pr_island, node, compare_peaks);

    while (pr_island != NULL) {
        t_list *temp = restore_path((t_islands *)pr_island->data);
        t_list *current = temp;

        while (current != NULL) {
            mx_push_back((t_list**)&current->data, node);
            mx_push_back(&paths, current->data);
            current = current->next;
        }

        mx_clear_list(&temp);
        pr_island = pr_island->next;
    }

    return paths;
}

bool compare_peaks(void *node1, void *node2, void *node) {
    if (((t_islands *) node1)->pr_island == NULL 
        && (((t_islands *) node2)->pr_island != NULL)) {
        while (((t_islands *)((t_islands *) node2)->pr_island->data)->pr_island) {
            node2 = ((t_islands *) node2)->pr_island->data;
        }

        return ((t_islands *) node)->index > ((t_islands *) node2)->index;
    }
    
    if (((t_islands *) node2)->pr_island == NULL 
        && (((t_islands *) node1)->pr_island != NULL)) {
        while (((t_islands *)((t_islands *) node1)->pr_island->data)->pr_island) {
            node1 = ((t_islands *) node1)->pr_island->data;
        }
        
        return ((t_islands *) node)->index < ((t_islands *) node1)->index;
    }

    return ((t_islands *) node1)->index > ((t_islands *) node2)->index;
}

