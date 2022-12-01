#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    if (!nbr) 
        return NULL;

    unsigned long num;
    int temp = 0;
    int count = 0;

    num = nbr;
    for ( ; num > 0; num /= 10) 
        count++;

    char *hex = (char *)malloc(count + 1);
    if(hex == NULL)
        return NULL;
    for (int i = 0; i < count; i++) 
        hex[i] = '\0';
    hex[count] = '\0';

    num = nbr;
    count = 0;
    while (num != 0) {
        if (num % 16 < 10) 
            hex[temp++] = 48 + num % 16;
        else 
            hex[temp++] = 87 + num % 16;
        count++;
        num = num / 16;
    }

    char *hex_reverted = (char *)malloc(count + 1);
    if(hex_reverted == NULL)
        return NULL;
    for (int i = 0; i < count; i++) 
        hex_reverted[i] = '\0';
    hex_reverted[count] = '\0';

    for (int i = 0, n = count - 1; i < count; i++, n--)
        hex_reverted[i] = hex[n];
    return hex_reverted;
}

// int main() {
//     printf("%s\n", mx_nbr_to_hex(52));
//     printf("%s\n", mx_nbr_to_hex(1000));
// }

