#include "../inc/libmx.h"

char *mx_itoa(int number) {
    char *buf = NULL;
    int size = 0;
    int base = 0;

    if (number == 0 && base == 0) {
        buf = mx_strnew(1);
        buf[0] = '0';
        return buf;
    }
    
    int current_num = number;
    if (current_num < 0) {
        size++;
        current_num *= -1;
        base++;
    }

    if (base != 0)
        buf = mx_strnew(size + 1);
    
    while (current_num != 0) {
        current_num /= 10;
        size++;
    }
    
    buf = mx_strnew(size);
    if (number < 0 && base == 1) {
        buf[0] = '-';
        number *= -1;
    }

    buf[size--] = '\0';
    while ((number != 0 && size >= 0) && buf[size] != '-') {
        buf[size--] = (number % 10) + '0';
        number /= 10;
    }
    return buf;
}

