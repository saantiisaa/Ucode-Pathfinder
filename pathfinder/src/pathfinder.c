#include "../inc/header.h"

void set_matrix(t_islands *islands) {
    for (int i = 1; i < size; i += 3) {
        int first1 = get_position(islands, islands->islands[i]);
        int second1 = get_position(islands, islands->islands[i + 1]);
        islands->isls_mtx[first1][second1] = arr_to_int(islands->islands[i + 2]);
        int first2 = get_position(islands, islands->islands[i + 1]);
        int second2 = get_position(islands, islands->islands[i]);
        islands->isls_mtx[first2][second2] = arr_to_int(islands->islands[i + 2]);
    }
}

void get_matrix(t_islands *islands) {
    islands->isls_mtx = (int**)malloc(8 * (number_of_islands + 1));
    for (int i = 0; i <= number_of_islands; islands->isls_mtx[i++] = NULL);
    islands->vld_isl = (int**)malloc(8 * (number_of_islands + 1));
    for (int i = 0; i <= number_of_islands; islands->vld_isl[i++] = NULL);
    for (int i = 0; i < number_of_islands; i++) {
        islands->isls_mtx[i] = malloc(8 * number_of_islands);
        islands->vld_isl[i] = malloc(8 * number_of_islands);
        for (int j = 0; j < number_of_islands; j++) {
            if(i != j) islands->isls_mtx[i][j] = INT_MAX;
            else islands->isls_mtx[i][j] = 0;
        }
    }
    set_matrix(islands);
}

void pathf_algorithm(t_islands *islands) {
    for (int i = 0; i < number_of_islands; i++) {
        for (int j = 0; j < number_of_islands; j++) {
            islands->vld_isl[i][j] = islands->isls_mtx[i][j];
            islands->vld_isl[j][i] = islands->isls_mtx[j][i];
        }
    }
    for (int k = 0; k < number_of_islands; k++) {
        for (int i = 0; i < number_of_islands; i++) {
            for (int j = i + 1; j < number_of_islands; j++) {
                int sum = islands->isls_mtx[i][k] + islands->isls_mtx[k][j];
                if(islands->isls_mtx[k][j] != INT_MAX && islands->isls_mtx[i][k] != INT_MAX && sum < islands->isls_mtx[i][j]) {
                    islands->isls_mtx[i][j] = sum;
                    islands->isls_mtx[j][i] = sum;
                }
            }
        }
    }
}

void get_paths(t_islands *bridge, char *file) {
    char *island = mx_strdup(file);
    number_of_islands = arr_to_int(island);
    for (int i = 0; island[i] != '\0'; i++) 
        if(island[i] == ',' || island[i] == '\n') island[i] = '-';
    size = mx_count_words(island, '-');
    bridge->islands = mx_strsplit(island, '-');
    bridge->valid_islands = (char **)malloc(sizeof(char*) * size);
    for (int i = 0; i < size; bridge->valid_islands[i++] = NULL);
    bridge->valid_islands[0] = mx_strdup(bridge->islands[1]);
    for (int i = 1, counter = 1; i < size; i++)
        if (mx_isdigit(bridge->islands[i][0]) == false)
            for (int j = 0; j < counter; j++) {
                if (mx_strcmp(bridge->valid_islands[j], bridge->islands[i]) == 0) break;
                if (j == counter - 1) bridge->valid_islands[counter++] = mx_strdup(bridge->islands[i]);
            }
    mx_strdel(&island); 
}

void pathfinder(char *file) {
    t_islands *bridge = malloc(sizeof(t_islands));
    get_paths(bridge, file);
    get_matrix(bridge);
    pathf_algorithm(bridge);
    t_paths *way = malloc(sizeof(t_paths));
    way->route = malloc(4 * (number_of_islands + 1));
    for (int i = 0; i < number_of_islands; i++) {
        for (int j = i + 1; j < number_of_islands; j++) {
            way->length = 1;
            way->route[0] = j;
            way->route[1] = i;
            pathfinder_output(bridge, way);
        }
    }
    char **arr = bridge->islands;
    mx_del_strarr(&arr);
    arr = bridge->valid_islands;
    mx_del_strarr(&arr);
    for (int i = 0; bridge->isls_mtx[i] != NULL; i++)
        free(bridge->isls_mtx[i]);
    free(bridge->isls_mtx);
    for (int i = 0; bridge->vld_isl[i] != NULL; i++) 
        free(bridge->vld_isl[i]);
    free(bridge->vld_isl);
    free(bridge);
    bridge = NULL;
    free(way->route);
    free(way);
    way = NULL;
}

