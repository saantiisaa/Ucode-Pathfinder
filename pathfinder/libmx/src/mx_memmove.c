#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *csrc = (char *)src;
    char *cdst = (char *)dst;
    char *temp = malloc(len);
    for (int i = 0; i < (int)len; i++)
        temp[i] = csrc[i];
    for (int i = 0; i < (int)len; i++)
        cdst[i] = temp[i];
    free(temp);
    return dst;
}

