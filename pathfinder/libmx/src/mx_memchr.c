#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *cs = (unsigned char*)s;
    while( n-- ) {
        if( *cs != (unsigned char)c )
            cs++;
        else return cs;
    }
    return NULL;
}

