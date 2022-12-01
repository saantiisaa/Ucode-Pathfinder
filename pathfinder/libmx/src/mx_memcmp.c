#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *cs1 = (unsigned char*) s1;
    unsigned char *cs2 = (unsigned char*) s2;
    size_t i;
    
    for (i = 0; cs1[i] == cs2[i] && i != n; i++) {
        if (cs1[i] == '\0' && cs2[i] == '\0')
            return 0;
    }
    return cs1[i] - cs2[i];
} 

