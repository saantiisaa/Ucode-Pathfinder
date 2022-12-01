#include "../inc/libmx.h"

char *mx_strnew(const int size) {
    char *result;
    if (size < 0)
        return NULL;
    result = malloc((size + 1) * sizeof(char));
    if (result == NULL)
        return NULL;
    for (int a = 0; a < size + 1; a++)
        result[a] = '\0';
    return result;
}

