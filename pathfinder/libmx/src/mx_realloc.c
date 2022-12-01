#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *newptr;
    size_t msize;
    msize = mx_strlen(ptr);

    if (size <= msize)
        return ptr;
    newptr = malloc(size);
    mx_memcpy(newptr, ptr, msize);
    
    free(ptr);
    return newptr;
}

