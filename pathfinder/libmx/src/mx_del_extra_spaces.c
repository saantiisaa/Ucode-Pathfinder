#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    int i = 0;
    int j = 0;
    char *temp = mx_strnew(mx_strlen(str));

    if (!str) 
        return NULL;

    while (str[i]) {
        if (!(mx_isspace(str[i]))) {
            temp[j] = str[i];
            j++;
        }
        if (mx_isspace(str[i + 1]) 
            && !(mx_isspace(str[i]))) {
            temp[j] = ' ';
            j++;
        }
        i++;
    }

    char *new = mx_strtrim(temp);
    mx_strdel(&temp);

    return new;
}

