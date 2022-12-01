#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned char *cbig = (unsigned char*) big; 
    unsigned char *clittle = (unsigned char*) little;
    unsigned char *p = cbig;

    while (little_len <= (big_len - (p - cbig))) {
        if (NULL != (p = mx_memchr(p, (int)(*clittle), big_len - (p - cbig)))) {
            if (0 == mx_memcmp(p, little, little_len))
                return p;
            else ++p;
        }
        else break;
    }
    return NULL;
}

