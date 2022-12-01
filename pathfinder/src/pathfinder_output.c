#include "../inc/header.h"

void print_path(t_islands *islands, t_paths *randd) {
    mx_printstr("Path: ");
    mx_printstr(islands->valid_islands[randd->route[1]]);
    mx_printstr(" -> ");
    mx_printstr(islands->valid_islands[randd->route[0]]);
    mx_printstr("\n"); 
}

void print_route(t_islands *islands, t_paths *randd) {
    mx_printstr("Route: ");
    for (int i = 1; i <= randd->length; i++) {
        mx_printstr(islands->valid_islands[randd->route[i]]); 
        if (i < randd->length) mx_printstr(" -> ");
    }
    mx_printstr("\n");
}

void print_distance(t_islands *islands, t_paths *randd) {
    int sum = 0;
    mx_printstr("Distance: ");
    for (int i = 1; i < randd->length; i++) {
        mx_printint(islands->vld_isl[randd->route[i]][randd->route[i + 1]]);
        sum += islands->vld_isl[randd->route[i]][randd->route[i + 1]];
        if (i < randd->length - 1) mx_printstr(" + ");
        else if (i > 1) {
            mx_printstr(" = ");
            mx_printint(sum);
        }
    }
    mx_printstr("\n");
}

void pathfinder_output(t_islands *islands, t_paths *randd) {
    int i = randd->route[randd->length];
    int j = randd->route[0];
    for (int p = 0; p < number_of_islands; p++)
        if (p != randd->route[randd->length] 
        && (islands->vld_isl[i][p] == islands->isls_mtx[i][j] - islands->isls_mtx[p][j])) {
            randd->length += 1;
            randd->route[randd->length] = p;
            pathfinder_output(islands, randd);
            randd->length -= 1;
        }
    if (randd->route[randd->length] == randd->route[0]) {
        mx_printstr("========================================\n");
        print_path(islands, randd);
        print_route(islands, randd);
        print_distance(islands, randd);
        mx_printstr("========================================\n");
    }
}

