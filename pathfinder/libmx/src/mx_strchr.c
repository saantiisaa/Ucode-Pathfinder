#include "../inc/libmx.h"

char *mx_strchr(const char *s, int c) {
    for (int i = 0; s[i] != '\0'; i++) {
        while (*s) {
            if (*s == c)
                return (char*) s;
            else
                s++;
        }
    }
    return 0;
}

