
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
        // Skip comments and empty lines
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\r')
            continue;

        // Remove newline character
        line[strcspn(line, "\r\n")] = 0;

        // Split into key and value
        char *delimiter = strchr(line, '=');
        if (!delimiter)
            continue;

        *delimiter = '\0';
        char *key = line;
        char *value = delimiter + 1;

        // Remove surrounding quotes from value (if any)
        size_t vlen = strlen(value);
        if (vlen >= 2 && value[0] == '"' && value[vlen - 1] == '"') {
            value[vlen - 1] = '\0';
            value++;
        }

        // Allocate memory for the environment variable string (key=value)
        // Note: putenv() requires the string to persist, so we leak this intentionally
        size_t env_len = strlen(key) + strlen(value) + 2;
        char *env_string = malloc(env_len);
        snprintf(env_string, env_len, "%s=%s", key, value);

        putenv(env_string);
    }
    fclose(file);
}

void env_init() {
    load_env(".env");
    env.stdout = atoi(getenv("stdout"));
    env.mailer = atoi(getenv("mailer"));
}
