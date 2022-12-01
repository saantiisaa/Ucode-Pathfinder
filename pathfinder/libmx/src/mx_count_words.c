#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    bool is_word = true;
    int count = 0;
    
    if (str == NULL)
        return -1;

    for (int i = 0; i < mx_strlen(str); i++) {
        if(str[i] == c)
            is_word = true;
        else if(is_word == true) {
            is_word = false;
            count++;
        }
    }
    return count;
}

