#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool(*cmp)(void *, void *)) {
    if (lst == NULL || cmp == NULL)
        return lst;

    int size = mx_list_size(lst);
    t_list *list = lst;

    for(int i = 0; i < size; i++) {
        t_list *tmp = list;
        for(int j = 0; j < size - i; j++) {
	        if(cmp(tmp->data,tmp->next->data)) {
				int *data = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = data;
			}
			tmp = tmp->next;
        }
    }

    return list;
}
