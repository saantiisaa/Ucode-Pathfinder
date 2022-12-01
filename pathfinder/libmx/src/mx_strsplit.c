#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    int count = 0;
    int size = 0;
    char **arr = NULL;

    if (!s) 
        return NULL;

    arr = (char**)malloc((mx_count_words(s, c) + 1) * sizeof(char*));
    while ((*s) && (*s != '\0')) {
        if (*s != c) {
            size = 0;
            while (s[size] && s[size] != c) 
                size++;
            arr[count] = mx_strndup(s, size);
            s += size;
            count++;
            continue;
        }
        s++;
    }
    arr[count] = NULL;
    return arr;
}

