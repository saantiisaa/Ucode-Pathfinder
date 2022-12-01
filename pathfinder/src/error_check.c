#include "../inc/header.h"

void print_line_not_match_format(int line) {
    char *line_err = mx_itoa(line + 1);
    mx_printerr("error: line ");
    mx_printerr(line_err);
    mx_strdel(&line_err); 
    mx_printerr(" is not valid\n");
    exit(1);
}

void print_ivalid_num_isl() {
    mx_printerr("error: invalid number of islands\n");
    exit(1);
}

void print_duplicate_bridges() {
    mx_printerr("error: duplicate bridges\n");
    exit(1);
}

void line_not_match_format(char **lines, char *file_name) {
    int i = 0, j = 1;
    int line_number = 1;
    while (file_name[i]){
        if(!mx_isdigit(file_name[0])){
            mx_del_strarr(&lines);
            print_line_not_match_format(0);
        }
        if (mx_isalpha(file_name[i + 1]) && file_name[i] == '\n') line_number++;
        if ((!mx_isalpha(file_name[i + 1]) && file_name[i] == '\n' && file_name[i + 1] != '\0')
            || (mx_isdigit(file_name[i]) && file_name[i + 1] == '\0')) {
            mx_del_strarr(&lines);
            mx_strdel(&file_name);
            print_line_not_match_format(line_number);
        }
        i++;
    }
    while (lines[j]) {
        int temp = 0;
        for (int i = 0; i < mx_strlen(lines[j]); i++){
            if (mx_isalpha(lines[j][i]) && (temp == 0 || temp == 1)) continue;
            if (lines[j][i] == '-' && temp == 0 && i != 0) {
                temp++;
                continue;
            }
            if (lines[j][i] == ',' && temp == 1 && mx_isdigit(lines[j][i+1])
                && (mx_get_char_index(lines[j], ',') -
                mx_get_char_index(lines[j], '-') > 1)) {
                temp *= -2;
                continue;
            }
            if (mx_isdigit(lines[j][i]) && temp == -2) continue;
            else {
                mx_strdel(&file_name);
                mx_del_strarr(&lines);
                print_line_not_match_format(j);
            }
        }
        j++;
    }    
}

void duplicate_bridges(char *file) {
    char **arr_of_islnds = mx_strsplit(file, '\n');
    int rows = 0;
    for(int i = 1; arr_of_islnds[i]; i++)
        rows++;
    char *new_arr[rows * 2][4];
    for (int i = 1; i < rows + 1; i++) {
        char **i1 = mx_strsplit(arr_of_islnds[i], '-');
        char **i2 = mx_strsplit(i1[1], ',');
        new_arr[i][0] = mx_strdup(i1[0]);
        if (i != 0) {
            new_arr[i][1] = mx_strdup(i2[0]);
            new_arr[i][2] = mx_strdup(i2[1]);
            new_arr[i][3] = NULL;
        }
        mx_del_strarr(&i1);
        mx_del_strarr(&i2);
    }
    char *bridges[rows * 2][1];
    for(int i = 1; i < rows + 1; i++) {
        char **tmp1 = mx_strsplit(arr_of_islnds[i], ',');
        bridges[i][0] = mx_strdup(tmp1[0]);
        mx_del_strarr(&tmp1);
    }
    int tmp_size = rows + 1;
    for(int i = 1; i < tmp_size; i++)
       for(int j = 1; j < tmp_size; j++)
            if(i != j)
                if((!mx_strcmp(new_arr[i][0], new_arr[j][1]) 
                 && !mx_strcmp(new_arr[i][1], new_arr[j][0])) 
                || mx_strcmp(bridges[i][0], bridges[j][0]) == 0) {
                    for (int i = 1; i <= rows; i++) {    
                        mx_strdel(&new_arr[i][0]);
                        mx_strdel(&new_arr[i][1]);
                        mx_strdel(&new_arr[i][2]);
                    }
                    for(int i = 1; i <= rows; i++) {
                        mx_strdel(&bridges[i][0]);
                    }
                    print_duplicate_bridges();
                }
    for (int i = 1; i <= rows; i++) {    
        mx_strdel(&new_arr[i][0]);
        mx_strdel(&new_arr[i][1]);
        mx_strdel(&new_arr[i][2]);
    }
    for(int i = 1; i <= rows; i++) {
        mx_strdel(&bridges[i][0]);
    }
    mx_del_strarr(&arr_of_islnds);
}

void error_check(int argc, char* argv[]) {
    char *file = read_data(argv[1]);
    if (argc != 2) {
        write(2, "usage: ./pathfinder [filename]\n", 32);
        exit(1);
    }
    int f = open(argv[1], O_RDONLY);
    if (f < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(1);
    }
    if (mx_strlen(file) == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(1);
    }
    if (file[0] == '-' || !mx_isdigit(file[0])) {
        mx_printerr("error: line 1 is not valid\n");
        exit(1);
    }
    char **lines = mx_strsplit(file, '\n');
    line_not_match_format(lines, file);
    mx_del_strarr(&lines);
    if (sum_of_brdgs_length(argv[1]) > INT_MAX) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(1);      
    }
    duplicate_bridges(file);
    mx_strdel(&file); 
}

