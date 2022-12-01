#include "../inc/header.h"

char *read_data(char *file_name) {
    int file = open(file_name, O_RDONLY);
    int temp_file = open(file_name, O_RDONLY);
    char s;
    long read_file = read(temp_file, &s, 1);
    int size = 0;
    if (file == -1) {
        close(file);
        return NULL;
    }
    while (read_file > 0) {
        read_file = read(temp_file, &s, 1);
        size++;
    }
    close(temp_file);
    if (size == 0) return NULL;
    char *new_str = mx_strnew(size);
    read(file, new_str, size);
    close(file);
    return new_str;
}

