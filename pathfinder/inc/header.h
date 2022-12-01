#ifndef HEADER_H
#define HEADER_H

#include "../libmx/inc/libmx.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <malloc/malloc.h>
// #include <malloc.h>
#include <fcntl.h>
#include <string.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int number_of_islands;
int size;

typedef struct s_islands {
    char **islands;
    int **isls_mtx;
    char **valid_islands;
    int **vld_isl;
}               t_islands;

typedef struct s_paths {
    int length;
    int *route;
}                t_paths;

void error_check(int argc, char* argv[]);
void duplicate_bridges(char *file);
void line_not_match_format(char **lines, char *file_name);
void print_line_not_match_format(int line);
void print_ivalid_num_isl();
void print_duplicate_bridges();
long sum_of_brdgs_length(char *file_name);
char *read_data(char *file_name);
void pathfinder(char *file);
int arr_to_int(char* str);
int get_position(t_islands *path, char *island);
int get_file_size(char* file_name);
int get_number_of_islands(char* file_name);
int count_row(char* file_name);
int arr_to_int(char* str);
void pathfinder_output(t_islands *islands, t_paths *randd);
void print_path(t_islands *islands, t_paths *randd);
void print_distance(t_islands *islands, t_paths *randd);
void print_route(t_islands *islands, t_paths *randd);
void get_matrix(t_islands *islands);
void set_matrix(t_islands *islands);
void pathf_algorithm(t_islands *islands);
void pathfinder(char *file);
void get_paths(t_islands *bridge, char *file);
void delete_arr(int **str);
void delete_list(int ***arr);

#endif
