/*
 * delivery_hints.h
 *
 * Delivery hints used to inform the reveiver about the expected destination of the file
 */

#ifndef _delivery_hints_H_
#define _delivery_hints_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct delivery_hints_t {
    char *dest_path; // string
    char *mode; // string

} delivery_hints_t;

delivery_hints_t *delivery_hints_create(
    char *dest_path,
    char *mode
);

void delivery_hints_free(delivery_hints_t *delivery_hints);

delivery_hints_t *delivery_hints_parseFromJSON(cJSON *delivery_hintsJSON);

cJSON *delivery_hints_convertToJSON(delivery_hints_t *delivery_hints);

#endif /* _delivery_hints_H_ */

