#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *new = (t_list*) malloc (sizeof(t_list));
    t_list *end = *list;
    new->data = data;
    new->next = NULL;

    if (*list == NULL) {
        *list = new;
        return;
    }
    while (end->next != NULL) {
        end = end->next;
    }
    end->next = new;
    return;
}

