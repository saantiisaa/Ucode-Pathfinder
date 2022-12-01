#include "../inc/libmx.h"

int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int first = 0;
    int last = size - 1;
    int mid = (first + last) / 2;
    *count = 0;
    int num = 0;

    while (first <= last) {
        (*count)++;
        if (mx_strcmp(arr[mid], s) > 0)
            last = mid - 1;
        else if (mx_strcmp (arr[mid], s) < 0) 
            first = mid + 1;
        else
            return mid;

        mid = (first + last) / 2;
    }
    if (num == 1) 
        return mid;
    else {
        *count = 0;
        return -1;
    }
    return -1;
}

