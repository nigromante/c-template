#define FILE_MAIN

#include "../../include/matrix.h"

int main(int argc, char **argv) {

    loader_init();

    int ret = pmain(argc, argv);

    loader_end();

    return ret;
}
