/*
 * send_file_request.h
 *
 * 
 */

#ifndef _send_file_request_H_
#define _send_file_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "send_options.h"



typedef struct send_file_request_t {
    char *destination; // string
    char *filepath; // string
    char *topic; // string
    struct send_options_t *options; //model

} send_file_request_t;

send_file_request_t *send_file_request_create(
    char *destination,
    char *filepath,
    char *topic,
    send_options_t *options
);

void send_file_request_free(send_file_request_t *send_file_request);

send_file_request_t *send_file_request_parseFromJSON(cJSON *send_file_requestJSON);

cJSON *send_file_request_convertToJSON(send_file_request_t *send_file_request);

#endif /* _send_file_request_H_ */

