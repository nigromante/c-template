#define MAIN_C

#include "include/libscall.h"
#include "include/loader.h"

int pmain(int argc, char **argv);

int main(int argc, char **argv) {

    loader_init();

    int ret = pmain(argc, argv);

    loader_end();

    return ret;
}
