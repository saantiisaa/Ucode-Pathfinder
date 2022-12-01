#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    int i = 0;
    int j = 0;
    int replace_size = mx_strlen(replace);
    int sub_size = mx_strlen(sub);
    char* buf;

    if (!str || !sub || !replace) 
        return NULL;

    for (i = 0; str[i] != '\0'; i++) {
        if (mx_strstr(&str[i], sub) == &str[i]) {
            j++;
            i += sub_size - 1;
        }
    }

    buf = (char*)malloc(i + j * (replace_size - sub_size) + 1);
    i = 0;
    while (*str) {
        if (mx_strstr(str, sub) == str) {
            mx_strcpy(&buf[i], replace);
            i += replace_size;
            str += sub_size;
        }
        else
            buf[i++] = *str++;
    }
    buf[i] = '\0';
    return buf;
}

