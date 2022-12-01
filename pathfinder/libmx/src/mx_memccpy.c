#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *csrc = (unsigned char *)src;
    unsigned char *cdst = (unsigned char *)dst;
    unsigned char *ptr;
    ptr = 0;
    
    for (size_t i = 0; i < n && ptr == 0; i++) {
        cdst[i] = csrc[i];
        if (csrc[i] == ((char)c))
            ptr = cdst + i + 1;
    }
    return ptr;
}

