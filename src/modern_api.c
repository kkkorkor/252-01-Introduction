#include "api_bridge_lab.h"

#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int modern_parse_year(const char *record, int *out_year) {
    /* TODO(student): strict parsing with strtol
       Requirements:
       - find ':'
       - fail if ':' missing
       - fail if no digits after ':'
       - fail if extra characters remain after number
       - fail on overflow/underflow via errno
       - on success, set *out_year and return 0
       - on failure, return -1
    */
    const char *colon;
    char *endptr;
    long year;

    colon = strchr(record,':');

    if(colon == NULL) return -1;

    errorno = 0;
    year = strtol(colon + 1, &endptr, 10);

    if(endptr == colon + 1){
        return -1;
    }

    if(errorno == ERANGE) return -1;

    if(*endptr !='\0'){
        return -1;
    }

    if(year < int_min || year > int_max) return -1;
    
    *out_year = int(year);
}

int modern_make_slug(const char *name, char *out, size_t out_size) {
    size_t i;

    /* TODO(student): safe slug conversion
       - same transformation as legacy_make_slug
       - must not write past out_size
       - always NUL-terminate on success
       - return 0 on success, -1 if output buffer too small
    */
    if (out_size == 0) {
        return -1;
    }

    for (i = 0; name[i] != '\0'; i++) {
        if(i+1 >= out_size){
            return -1;
        }
    }

    if (name[i] != '\0') {
        return -1;
    }

    out[i] = '\0';
    return 0;
}
