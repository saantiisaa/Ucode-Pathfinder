#include "../inc/header.h"

int get_file_size(char* file_name) {
    char *str = read_data(file_name);
    int file_size = mx_strlen(str);
    mx_strdel(&str); 
	return file_size;
}

int get_number_of_islands(char* file_name) {
    char *str = NULL;
    int number_of_islands = 0;
    str = read_data(file_name);
    for (int i = 0; str[i] != '\n'; ++i)
        number_of_islands = number_of_islands * 10 + str[i] - '0';
    mx_strdel(&str); 
    return number_of_islands;
}

int count_row(char* file_name) {
    char* arr = read_data(file_name);
    int count_row = 0;
    for (int i = 0; i < get_file_size(file_name); i++) 
        if (arr[i] == '\n') count_row++;
    mx_strdel(&arr); 
    return count_row;
}

int arr_to_int(char* str) {
    int sign = 1, base = 0, i = 0; 
    while (str[i] == ' ') i++;
    if (str[i] == '-' || str[i] == '+')
        sign = 1 - 2 * (str[i++] == '-');
    while (str[i] >= '0' && str[i] <= '9') {
        if (base > INT_MAX / 10 
        || (base == INT_MAX / 10
        && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MAX;
        }
        base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}

bool compare_two_arrays(int count1, int count2, int *s1, int *s2) {
    if (!s1 || !s2) return false;
    if (count1 == count2) 
        for (int i = 0; s1[i] == s2[i]; i++) 
            if (i == count1 - 1) 
                return true;
    return false;
}

void delete_arr(int **str) {
	if (*str && str) {
		free(*str);
		*str = NULL;
	}
}

void delete_list(int ***arr) {
    if (arr == NULL) return;
    int ***p = arr;
    int **pp = *arr;
    while (**p != NULL) {
        delete_arr(*p);
        (*p)++;   
    }
    free(pp);
    *arr = NULL;
}

// void mx_del_strarr2x(char ****arr) {
//     for (int i = 0; (**arr)[i] != NULL; i++)
//     mx_del_strarr(&(**arr)[i]);
//   free(**arr);
//   **arr = NULL;
// }

int number_in_line(const char *str, char c){
	if (!str) return -2;
	for (int i = 0; str[i]; i++){
		if (str[i] == c) return i;
	}
	return -1;
}

int get_position(t_islands *path, char *island) {
    for (int i = 0; i < number_of_islands; i++)
        if (mx_strcmp(island, path->valid_islands[i]) == 0) return i;
    return 0;
}

long sum_of_brdgs_length(char *file_name) {
    char *str = read_data(file_name);
    int size = mx_strlen(str);
    // char **strarr = mx_strsplit(str, ',');
    long sum = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == ',') 
            sum += arr_to_int(&(str[i + 1]));
    }
    mx_strdel(&str); 
    return sum;
}
// char *str_maker(const char *str, char *arr, char *s) {
//     int count = 0;
// 	   for (int i = 0; str[i]; i++) {
// 		  if (str[i] == s) 
//            count = i;
// 	   }
//     arr = mx_strndup(str, count);
//     str = mx_strlen(arr) + 1 + str;
//     return arr;
// }

// void get_length_of_bridge(char* file_name) {
//     char *str = read_data(file_name);
//     for (int i = 0; i < count_row(str); i++) {

//     }
// }

