#include "../inc/header.h"

int main(int argc, char *argv[]) {
    error_check(argc, argv);
    char *data = read_data(argv[1]);
    pathfinder(data);
    mx_strdel(&data);
    return 0;
}

