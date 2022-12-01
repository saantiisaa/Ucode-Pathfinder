#include "../inc/libmx.h"

int mx_strlen(const char *s);

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    s1[mx_strlen(s1) + mx_strlen(s2) + 1] = '\0';
    for (int i = 0; i < mx_strlen(s1) + mx_strlen(s2) + 1; i++) 
        s1[mx_strlen(s1) + i] = s2[i];
    return s1;
}

