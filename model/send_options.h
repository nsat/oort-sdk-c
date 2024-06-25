/*
 * send_options.h
 *
 * options to apply to a send request
 */

#ifndef _send_options_H_
#define _send_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "ttl_params.h"



typedef struct send_options_t {
    struct ttl_params_t *ttl_params; //model
    int reliable; //boolean
    list_t* tags; //map

} send_options_t;

send_options_t *send_options_create(
    ttl_params_t *ttl_params,
    int reliable,
    list_t* tags
);

void send_options_free(send_options_t *send_options);

send_options_t *send_options_parseFromJSON(cJSON *send_optionsJSON);

cJSON *send_options_convertToJSON(send_options_t *send_options);

#endif /* _send_options_H_ */

