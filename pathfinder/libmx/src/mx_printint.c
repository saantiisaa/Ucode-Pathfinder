#include "../inc/libmx.h"

void mx_printchar(char c);

void mx_printint(int n) {
	int buff[256];
	int length = 0;

    if (n == 0) {
        mx_printchar(n + '0');
    }
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
	if (n < 0) {
        mx_printchar('-');
        n *= -1;
    }
	while (n != 0) {
		buff[length++] = '0' + n % 10;
		n /= 10;
    }
    for(int i = length - 1; i >= 0; i--) {
        mx_printchar(buff[i]);
    }
}

