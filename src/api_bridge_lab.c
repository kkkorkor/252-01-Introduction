#include "api_bridge_lab.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 512
#define MAX_SLUG 128

static void trim_newline(char *s) {
    size_t n = strlen(s);
    if (n > 0 && s[n - 1] == '\n') {
        s[n - 1] = '\0';
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE];
    int row = 0;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <records-file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        char record_copy[MAX_LINE];
        char *colon;
        char *name;
        int legacy_year;
        int modern_year;
        int modern_year_ok;
        char legacy_slug[MAX_SLUG];
        char modern_slug[MAX_SLUG];
        int modern_slug_ok;

        trim_newline(line);
        if (line[0] == '\0') {
            continue;
        }

        row++;
        snprintf(record_copy, sizeof(record_copy), "%s", line);

        colon = strchr(line, ':'); //strchr for find character in string
        if (colon != NULL) {
            *colon = '\0'; 
            // ':' replace with '\0', so from "Ada Lovelace\01815" will cut to just "Ada Lovelace"
        }
        name = line;

        legacy_year = legacy_parse_year(record_copy);
        modern_year_ok = modern_parse_year(record_copy, &modern_year);

        legacy_make_slug(name, legacy_slug);
        modern_slug_ok = modern_make_slug(name, modern_slug, sizeof(modern_slug));

        printf("%02d | %s | legacy=%s:%d | ", row, name, legacy_slug, legacy_year);

        if (modern_year_ok == 0 && modern_slug_ok == 0) {
            printf("modern=%s:%d | status=OK\n", modern_slug, modern_year);
        } else {
            printf("modern=ERROR | status=MIGRATE\n");
        }
    }

    fclose(fp);
    return 0;
}
