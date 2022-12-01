#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    int size = mx_strlen(str);

    if (!str) 
        return NULL;

    while (mx_isspace(*str)) 
        str++;

    while (mx_isspace(str[size - 1])) 
        size--;

    return mx_strndup(str, size);
}

