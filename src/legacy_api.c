#include "api_bridge_lab.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int legacy_parse_year(const char *record) {
    const char *colon;

    /* TODO(student): legacy parsing style:
       - find ':'
       - if missing, return 0
       - parse with atoi(colon + 1)
    */
    colon = strchr(record, ':');
    if (colon == NULL) {
        return 0;
    }

    return atoi(colon + 1);
}

void legacy_make_slug(const char *name, char *out) {
    size_t i;

    /* TODO(student):
       - convert letters to lowercase
       - replace spaces with '_'
       - copy other characters as-is
    */
    for (i = 0; name[i] != '\0'; i++) {
        if(name[i] == ' '){
            out[i] = '_';
        }else{
            out[i] = tolower((unsigned char)name[i]);
        }  
    }
    out[i] = '\0';
}
