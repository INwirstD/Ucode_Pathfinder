#include "libmx.h"

int mx_list_size(t_list *list) {
    int check = 0;
    t_list *temp = list;

    while (temp != NULL) {
        check++;
        temp = temp->next;
    }

    return check;
}

