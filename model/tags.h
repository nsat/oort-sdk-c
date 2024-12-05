/*
 * tags.h
 *
 * a structure for optional file tags
 */

#ifndef _tags_H_
#define _tags_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct tags_t {
    char *token; // string

} tags_t;

tags_t *tags_create(
    char *token
);

void tags_free(tags_t *tags);

tags_t *tags_parseFromJSON(cJSON *tagsJSON);

cJSON *tags_convertToJSON(tags_t *tags);

#endif /* _tags_H_ */

