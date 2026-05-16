#define FILE_MAIN

#include "../include/matrix.h"

int main(int argc, char **argv) {

    loader_init();

    proc_run(argc, argv);

    loader_end();

    return 0;
}
