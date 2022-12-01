#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if (x > 0) { 
        for (int i = 1; i < x; i++) {
            if(i * i == x)
                return i;
        }
    }
    else 
        return 0;
    return 0;
}

