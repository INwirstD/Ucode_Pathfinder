#include "../inc/pathfinder.h"

void mx_printerr(const char *s) {
    write(2, s, mx_strlen(s));
}

void mx_clear_list(t_list **list) {
    if (list == NULL || *list == NULL) {
        return;  
    }

    t_list *current = *list;
    t_list *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *list = NULL;  
}

bool mx_is_positive_integer(const char *str) {
    if (str == NULL) {
        return false; 
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (!mx_isdigit(str[i])) {
            return false; 
        }
    }

    return true; 
}

