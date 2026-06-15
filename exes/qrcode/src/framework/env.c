
#define ENV_C
#include "include/env.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load_env(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open .env file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\r')
            continue;

        line[strcspn(line, "\r\n")] = 0;

        char *delimiter = strchr(line, '=');
        if (!delimiter)
            continue;
        *delimiter = '\0';

        char *key = line;
        char *value = delimiter + 1;

        setenv(key, value, 1);
    }
    fclose(file);
}
