#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *cs = (unsigned char *)s + mx_strlen(s);
	while (n--) {
		if (*cs == (unsigned char)c)
			return cs;
		cs--;
	}
	return NULL;
}
