#include "libmx.h"

t_list *mx_sort_list(t_list *lst, void *peak, bool (*cmp)(void *, void *, void *)) {
    if (lst == NULL || peak == NULL || cmp == NULL) {
        return NULL; 
    }

    for (t_list *i = lst; i != NULL; i = i->next) {
        for (t_list *j = i->next; j != NULL; j = j->next) {
            if (cmp(i->data, j->data, peak)) {
                void *temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    return lst;
}

