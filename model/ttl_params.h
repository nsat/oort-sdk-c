/*
 * ttl_params.h
 *
 * TTL parameters for a sent item
 */

#ifndef _ttl_params_H_
#define _ttl_params_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct ttl_params_t {
    int urgent; //numeric
    int bulk; //numeric
    int surplus; //numeric

} ttl_params_t;

ttl_params_t *ttl_params_create(
    int urgent,
    int bulk,
    int surplus
);

void ttl_params_free(ttl_params_t *ttl_params);

ttl_params_t *ttl_params_parseFromJSON(cJSON *ttl_paramsJSON);

cJSON *ttl_params_convertToJSON(ttl_params_t *ttl_params);

#endif /* _ttl_params_H_ */

